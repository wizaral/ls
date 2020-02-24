#include "uls.h"

t_file get_file_fields(t_dir *dir, struct dirent *drt) {
    struct stat st;
    t_file file;
    t_get *get = &dir->info->get;

    lstat(mx_strjoin(directory, drt->d_name), &st);
    file.fields.access = get->access();
    file.fields.grp = get->grp();
    file.fields.inode = get->inode();
    file.fields.links = get->links();
    file.fields.size = get->size();
    file.fields.user = get->user();
    file.fields.bsize = get->bsize();
    file.fields.time = get->time();

    mx_push_backward(&dir->array, &file);
}

void hidden(t_dir *dir) {
    // struct dirent *file;
    // ...
    struct dirent *drt;
    t_file file;

    if (dir->dir != NULL)
    for (int i = 0; i < 2; ++i, readdir(dir->dir));
    while ((drt = readdir(dir->dir)) != NULL)
        file = get_file_fields(dir, drt);
}
