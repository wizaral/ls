#include "uls.h"

void mx_not_printable(t_info *info, t_dir *dir, t_file *file, t_stat *st) {
    file->fields.name = mx_strndup(dir->file->d_name, dir->file->d_namlen);
    file->lengths.name = dir->file->d_namlen;
    if (dir->off.name < file->lengths.name)
        dir->off.name = file->lengths.name;
    ++info;
    ++st;
}

void mx_only_printable(t_info *info, t_dir *dir, t_file *file, t_stat *st) {
    file->fields.name = mx_strndup(dir->file->d_name, dir->file->d_namlen);
    file->lengths.name = dir->file->d_namlen;
    if (dir->off.name < file->lengths.name)
        dir->off.name = file->lengths.name;
    for (int i = file->lengths.name - 1; i > -1; --i)
        if (!mx_isprint(file->fields.name[i]))
            file->fields.name[i] = '?';
    ++info;
    ++st;
}

void mx_octal_printable(t_info *info, t_dir *dir, t_file *file, t_stat *st) {
    size_t offset = mx_octal_off(dir->file->d_name, dir->file->d_namlen);
    size_t length = mx_octal_len(dir->file->d_name, dir->file->d_namlen);
    char *octal_name = (file->fields.name = malloc(length));
    size_t pos = 0;

    for (const char *name = dir->file->d_name; *name; ++name) {
        if (MX_OCTAL(*name)) {
            octal_name[pos++] = '\\';
            octal_name[pos++] = '0' + (*name >> 6);
            octal_name[pos++] = '0' + ((*name >> 3) & 7);
            octal_name[pos++] = '0' + (*name & 7);
        }
        else
            octal_name[pos++] = *name;
    }

    ++info;
    ++st;
}

static inline void change_escape(char *octal_name, char esc, size_t *pos) {
    octal_name[(*pos)++] = '\\';
    octal_name[(*pos)++] = "\\\"abfnrtv"[MX_GET_ESC(esc)];

    // if (esc == '\\')
    //     octal_name[*pos] = '\\';
    // else if (esc == '\"')
    //     octal_name[*pos] = '"';
    // else if (esc == '\a')
    //     octal_name[*pos] = 'a';
    // else if (esc == '\b')
    //     octal_name[*pos] = 'b';
    // else if (esc == '\f')
    //     octal_name[*pos] = 'f';
    // else if (esc == '\n')
    //     octal_name[*pos] = 'n';
    // else if (esc == '\r')
    //     octal_name[*pos] = 'r';
    // else if (esc == '\t')
    //     octal_name[*pos] = 't';
    // else if (esc == '\v')
    //     octal_name[*pos] = 'v';
    // ++*pos;
}

void mx_escape_printable(t_info *info, t_dir *dir, t_file *file, t_stat *st) {
    size_t offset = mx_octal_off(dir->file->d_name, dir->file->d_namlen);
    size_t length = mx_escape_len(dir->file->d_name, dir->file->d_namlen);
    char *octal_name = (file->fields.name = malloc(length));
    size_t pos = 0;

    for (const char *name = dir->file->d_name; *name; ++name) {
        if (MX_ESCAPE(*name))
            change_escape(octal_name, *name, &pos);
        else if (MX_OCTAL(*name)) {
            octal_name[pos++] = '\\';
            octal_name[pos++] = '0' + (*name >> 6);
            octal_name[pos++] = '0' + ((*name >> 3) & 7);
            octal_name[pos++] = '0' + (*name & 7);
        }
        else
            octal_name[pos++] = *name;
    }

    ++info;
    ++st;
}
