#include "uls.h"

static inline void init_dir(t_dir *dir, char *name) {
    dir->dir = opendir(name);

    if (dir->dir) {
        dir->name = name;
        dir->len = mx_strlen(name);
        dir->total = 0;
        dir->file = NULL;
        dir->filename = NULL;
        dir->array.cap = MX_VECTOR_DEFAULT_SIZE;
        dir->array.bytes = sizeof(t_file);
        dir->array.size = 0;
        dir->array.arr = malloc(MX_VECTOR_DEFAULT_SIZE * sizeof(t_file));
        mx_memset(&dir->off, 0, sizeof(t_offset));
        dir->has_bc = false;
    }
}

void mx_process_dir(t_info *info, char *name) {
    t_dir dir;

    init_dir(&dir, name);
    if (dir.dir) {
        info->recursion(info, &dir);
        closedir(dir.dir);
    }
    else {
        info->return_val = 1;
        mx_printstrlen("uls: ", 5, 2);
        perror(mx_get_file_name(name));
    }
}

// static void process_files(t_info *info) {
//     char **end = mx_end(&info->files);
//     t_dir dir;

//     dir.
//     for (char **i = (char **)info->files.arr; i < end; ++i) {

//     }

//     mx_printchar('\n', 1);
// }

void mx_process_args(t_info *info) {
    char *dir_name = NULL;

    // if (info->files.size > 0)
    //     process_files(info);

    if (info->dirs.size > 1) {
        for (size_t i = 0; i < info->dirs.size; ++i) {
            dir_name = *(char **)mx_at(&info->dirs, i);
            mx_printstr(dir_name, 1);
            mx_printstrlen(":\n", 2, 1);
            mx_process_dir(info, dir_name);
            if (i + 1 != info->dirs.size)
                mx_printchar('\n', 1);
        }
    }
    else if (info->dirs.size)
        mx_process_dir(info, *(char **)mx_get_front(&info->dirs));
}
