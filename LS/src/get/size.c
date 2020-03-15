#include "uls.h"

static inline void short_format(t_file *file, t_stat *st) {
    int major = MX_MAJOR(st->st_rdev);
    int minor = MX_MINOR(st->st_rdev);
    int len1 = mx_unumlen(major, 10);
    int len2 = mx_unumlen(minor, 10);

    file->fields.size = mx_strnew(9, ' ');
    file->fields.size[3] = ',';
    mx_ulltoa_s(major, file->fields.size + 3 - len1, len1);
    mx_ulltoa_s(minor, file->fields.size + 8 - len2, len2);
}

static inline void long_format(t_file *file, t_stat *st) {
    int major = MX_MAJOR(st->st_rdev);
    int minor = MX_MINOR(st->st_rdev);
    int len1 = mx_unumlen(major, 10);
    int len2 = mx_unumlen(minor, 16);

    file->fields.size = mx_strnew(16, ' ');
    mx_memset(file->fields.size + 5, '0', 10);
    file->fields.size[3] = ',';
    file->fields.size[6] = 'x';
    mx_ulltoa_s(major, file->fields.size + 3 - len1, len1);
    mx_ulltoh_s(minor, file->fields.size + 15 - len2, len2);
}

static void minor_major(t_dir *dir, t_file *file, t_stat *st) {
    if (MX_MINOR(st->st_rdev) < 256)
        short_format(file, st);
    else
        long_format(file, st);
    file->lengths.size = 8;
    if (dir->off.size < 8)
        dir->off.size = 8;
}

void mx_size_b(t_dir *dir, t_file *file, t_stat *st) {
    if (MX_ISCHR(st->st_mode) || MX_ISBLK(st->st_mode)) {
        minor_major(dir, file, st);
    }
    else {
        int size_len = mx_numlen(st->st_size, 10);
        char *str = mx_strnew(size_len + 1, ' ');

        file->fields.size = mx_lltoa_s(st->st_size, str, size_len);
        file->lengths.size = size_len;
        if (dir->off.size < size_len)
            dir->off.size = size_len;
    }
}
