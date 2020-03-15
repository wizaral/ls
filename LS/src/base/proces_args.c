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

static inline void get_info(t_info *info, t_dir *dir) {
    static t_stat st;
    t_file file_info = {{0}, {0}, {0}, 0, 0};
    void (**func)(t_dir *, t_file *, t_stat *) =
        (void (**)(t_dir *, t_file *, t_stat *))&info->get;

    lstat(dir->filename, &st);
    file_info.size = st.st_size;
    file_info.mode = st.st_mode;
    mx_memcpy(&file_info.time, &st.st_atimespec + info->time_type,
                sizeof(t_timespec));
    file_info.fields.name = dir->filename;
    file_info.lengths.name = mx_strlen(dir->filename);
    if (dir->off.name < file_info.lengths.name)
        dir->off.name = file_info.lengths.name;

    for (int i = 1; i < 11; ++i)
        func[i](dir, &file_info, &st);
    mx_push_backward(&dir->array, &file_info);
}

static void process_files(t_info *info) {
    char **end = mx_end(&info->files);
    t_dir dir = {0, 0, 0, 0, 0, 0, {MX_VECTOR_DEFAULT_SIZE, 0, sizeof(t_file),
        malloc(sizeof(t_file) * MX_VECTOR_DEFAULT_SIZE)}, {0}};

    for (char **i = (char **)info->files.arr; i < end; ++i) {
        dir.filename = *i;
        get_info(info, &dir);
    }

    mx_sort(dir.array.arr, dir.array.size, dir.array.bytes, info->cmp);
    info->write(info, &dir);
    mx_free_dir(&dir);
}

void mx_process_args(t_info *info) {
    char *dir_name = NULL;

    if (info->files.size > 0)
        process_files(info);
    if (info->files.size && info->dirs.size)
        mx_printchar('\n', 1);

    if (info->dirs.size > (info->files.size == 0)) {
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
