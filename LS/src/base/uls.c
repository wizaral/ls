#include "uls.h"

// static bool check_block_char(char *name) {
//     return false;
// }

// static void free_dir(t_dir *dir) {

// }

static void get_info(t_info *info, t_dir *dir, t_dirent *file) {
    static t_stat st;
    t_file file_info = {{0}, {0}, {0}, 0, 0};
    void (**func)(t_info *, t_dir *, t_file *, t_stat *) =
        (void (**)(t_info *, t_dir *, t_file *, t_stat *))&info->get;

    dir->filename = get_name_full(dir->name, dir->len,
                                file->d_name, file->d_namlen);

    lstat(dir->filename, &st);
    file_info.size = st.st_size;
    file_info.mode = st.st_mode;
    mx_memcpy(&file_info.time, ((uint8_t *)&st.st_atimespec + info->time_type), sizeof(t_timespec));

    for (int i = 0; i < 14; ++i)
        func[i](info, dir, &file_info, &st);
    mx_push_backward(&dir->array, &file_info);
    mx_strdel(&dir->filename);
}

void mx_uls(t_info *info, t_dir *dir) {
    t_dirent *(*read)(DIR *) = info->read;
    dir->file = read(dir->dir);

    // dir->has_bc = check_block_char(dir->name);
    for (DIR *pdir = dir->dir; dir->file; dir->file = read(pdir))
        get_info(info, dir, dir->file);

    mx_sort(dir->array.arr, dir->array.size, dir->array.bytes, info->cmp);
    info->write(info, dir);
    // free_dir();
}

void mx_recursion(t_info *info, t_dir *dir) {
    t_dirent *(*read)(DIR *) = info->read;
    t_dirent *file = read(dir->dir);

    // dir->has_bc = check_block_char();
    for (DIR *pdir = dir->dir; file; file = read(pdir))
        get_info(info, dir, file);

    mx_sort(dir->array.arr, dir->array.size, dir->array.bytes, info->cmp);
    info->write(info, dir);
    // recursion magic

    uint8_t *end = dir->array.arr + dir->array.size * dir->array.bytes;
    for (uint8_t *i = dir->array.arr; i < end; i += dir->array.bytes) {
        t_file *file = (t_file *)i;
        if (MX_ISDIR(file->mode) && !(file->fields.name[0] == '.' && (file->fields.name[1] == '\0' || (file->fields.name[1] == '.' && file->fields.name[2] == '\0'))))
            mx_process_dir(info, get_name_full(dir->name, dir->len, file->fields.name, file->lengths.name));
    }
    // free_dir();
}
