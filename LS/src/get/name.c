#include "uls.h"

void mx_get_name(t_dir *d, t_file *f, struct stat *s) {
    f->fields.name = hui_mne_a_ne_imya_bez_direnta();
}
