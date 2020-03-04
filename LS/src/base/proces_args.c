#include "uls.h"

void mx_foreach_file(t_info *info, t_file *arr, size_t size,
                     void (*f)(t_info *, t_file *)) {
    if (info && arr && size && f)
        for (size_t i = 0; i < size; ++i)
            f(info, arr + i);
}

void mx_foreach_file_reverse(t_info *info, t_file *arr, size_t size,
                             void (*f)(t_info *, t_file *)) {
    if (info && arr && size && f) {
        for (size_t i = size - 1; i > 0; --i)
            f(info, arr + i);
        f(info, arr);
    }
}

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

void mx_process_args(t_info *info) {
    t_dir dir;

    // printf("F: %zu\n", info->files.size);

    // тут сначала выводим файлы
    // но не выводим))0)

    // printf("D: %zu\n", info->directories.size);

    // потом запускаем для папок
    for (size_t i = 0; i < info->directories.size; ++i) {
        init_dir(&dir, *(char **)mx_at(&info->directories, i));
        info->recursion(info, &dir);
        closedir(dir.dir);
    }
}
