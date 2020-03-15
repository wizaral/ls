#include "uls.h"

void mx_free_dir(t_dir *dir) {
    t_file *end = mx_end(&dir->array);
    t_printable *fields = NULL;

    for (t_file *i = (t_file *)dir->array.arr; i < end; ++i) {
        fields = &i->fields;
        fields->arrow ? free(fields->arrow) : (void)0;
        fields->bsize ? free(fields->bsize) : (void)0;
        fields->grp ? free(fields->grp) : (void)0;
        fields->inode ? free(fields->inode) : (void)0;
        fields->links ? free(fields->links) : (void)0;
        fields->size ? free(fields->size) : (void)0;
        fields->time ? free(fields->time) : (void)0;
        fields->user ? free(fields->user) : (void)0;
        free(fields->name);
    }
    free(dir->array.arr);
}
