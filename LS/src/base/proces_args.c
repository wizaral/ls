#include "uls.h"

static inline void init_dir(t_dir *dir, char *name) {
    dir->dir = opendir(name);
    dir->name = name;
    dir->len = mx_strlen(name);
    dir->file = NULL;
    dir->filename = NULL;
    dir->array.cap = MX_VECTOR_DEFAULT_SIZE;
    dir->array.bytes = sizeof(t_file);
    dir->array.size = 0;
    dir->array.arr = malloc(MX_VECTOR_DEFAULT_SIZE * sizeof(t_file));
    mx_memset(&dir->off, 0, sizeof(t_offset));
    dir->has_bc = false;
}

void mx_process_dir(t_info *info, char *name) {
    t_dir dir;

    init_dir(&dir, name);
    info->recursion(info, &dir);
    closedir(dir.dir);
    mx_realloc(name, 0);
}

void mx_process_args(t_info *info) {
    // printf("F: %zu\n", info->files.size);

    // тут сначала выводим файлы
    // но не выводим))0)

    // printf("D: %zu\n", info->directories.size);

    // потом запускаем для папок
    for (size_t i = 0; i < info->directories.size; ++i)
        mx_process_dir(info, *(char **)mx_at(&info->directories, i));
}
