#include "uls.h"

// should placed in utils
// static void free_dir(t_dir *dir) {
// }

static void get_info(t_info *info, t_dir *dir, t_dirent *file) {
    static t_stat st;
    t_file file_info = {{0}, {0}, {0}, 0, 0};
    void (**func)(t_info *, t_dir *, t_file *, t_stat *) =
        (void (**)(t_info *, t_dir *, t_file *, t_stat *))&info->get;

    dir->filename = mx_get_path_name(dir->name, dir->len, file->d_name, file->d_namlen);
    lstat(dir->filename, &st);
    dir->total += st.st_blocks;
    file_info.size = st.st_size;
    file_info.mode = st.st_mode;
    mx_memcpy(&file_info.time, &st.st_atimespec + info->time_type, sizeof(t_timespec));

    for (int i = 0; i < 14; ++i)
        func[i](info, dir, &file_info, &st);
    mx_push_backward(&dir->array, &file_info);
    mx_strdel(&dir->filename);
}

void mx_uls(t_info *info, t_dir *dir) {
    t_dirent *(*read)(DIR *) = info->read;

    dir->file = read(dir->dir);
    dir->has_bc = mx_check_block_char(dir->name);
    for (DIR *pdir = dir->dir; dir->file; dir->file = read(pdir))
        get_info(info, dir, dir->file);

    mx_sort(dir->array.arr, dir->array.size, dir->array.bytes, info->cmp);
    info->print_total(info, dir);
    info->write(info, dir);
    // free_dir();
}

void mx_recursion(t_info *info, t_dir *dir) {
    t_dirent *(*read)(DIR *) = info->read;

    dir->file = read(dir->dir);
    dir->has_bc = mx_check_block_char(dir->name);
    for (DIR *pdir = dir->dir; dir->file; dir->file = read(pdir))
        get_info(info, dir, dir->file);

    mx_sort(dir->array.arr, dir->array.size, dir->array.bytes, info->cmp);
    info->print_total(info, dir);
    info->write(info, dir);

    t_file *end = (t_file *)(dir->array.arr + dir->array.size * dir->array.bytes);
    for (t_file *i = (t_file *)dir->array.arr; i < end; ++i) {
        if (MX_ISDIR(i->mode) && mx_strcmp(i->fields.name, ".") && mx_strcmp(i->fields.name, "..")) {
            char *fullname = mx_get_path_name(dir->name, dir->len, i->fields.name, i->lengths.name);
            mx_printchar('\n', 1);
            mx_printstr(fullname, 1);
            mx_printstrlen(":\n", 2, 1);
            mx_process_dir(info, fullname);
            free(fullname);
        }
    }
    // free_dir();
}
