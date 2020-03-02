#include "uls.h"

void get_info(t_dir *dir, t_dirent *file) {
    static t_stat st;
    t_file file_info = {0};
    char *name = mx_strjoin(dir->name, file->d_name);
    void (**func)(t_dir *, t_file *, t_stat *) =
    (void (**)(t_dir *, t_file *, t_stat *))&dir->info->get;

    lstat(name, &st);
    for (int i = 0; i < 14; ++i)
        func[i](dir, &file_info, &st);
    mx_push_backward(&dir->array, &file_info);
    free(name);
}

void mx_uls(t_dir *dir, DIR *pdir) {
    t_dirent *file = dir->info->read(pdir);

    for (; file; file = dir->info->read(pdir))
        get_info(dir, file);
    mx_sort(dir->files, dir->array.size, dir->array.bytes, dir->info->cmp);
    dir->info->write(dir);

    // recursion ?
    // freed memory ?
}
