#include "uls.h"

// static bool check_block_char() {

// }

// static void free_dir(t_dir *dir) {

// }

static void get_info(t_info *info, t_dir *dir, t_dirent *file) {
    static t_stat st;
    t_file file_info = {0};
    void (**func)(t_info *, t_dir *, t_file *, t_stat *) =
        (void (**)(t_info *, t_dir *, t_file *, t_stat *))&dir->info->get;

    dir->filename = mx_strcpy(
        mx_strcpy(
            mx_strcpy(
                malloc(dir->len + file->d_namlen + 2),
                dir->name) + dir->len,
            "/") + dir->len + 1,
        file->d_name,
        file->d_namlen);

    lstat(dir->filename, &st);
    for (int i = 0; i < 14; ++i)
        func[i](info, dir, &file_info, &st);
    mx_push_backward(&dir->array, &file_info);
    free(dir->filename);
}

void mx_uls(t_info *info, t_dir *dir) {
    t_dirent *(*read)(DIR *) = dir->info->read;
    t_dirent *file = read(dir->dir);

    // dir->has_bc = check_block_char();
    for (DIR *pdir = dir->dir; file; file = read(pdir))
        get_info(info, dir, file);

    mx_sort(dir->files, dir->array.size, dir->array.bytes, dir->info->cmp);
    info->write(info, dir);
    // free_dir();
}

void mx_recursion(t_info *info, t_dir *dir) {
    t_dirent *(*read)(DIR *) = dir->info->read;
    t_dirent *file = read(dir->dir);

    // dir->has_bc = check_block_char();
    for (DIR *pdir = dir->dir; file; file = read(pdir))
        get_info(info, dir, file);

    mx_sort(dir->files, dir->array.size, dir->array.bytes, dir->info->cmp);
    info->write(info, dir);
    // recursion magic
    // free_dir();
}
