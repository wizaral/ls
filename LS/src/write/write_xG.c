#include "uls.h"

// ДОДЕЛАТЬ СТРУКТУРЫ ТОГДА ИЗИ ЭТО ПЕРЕПИШУ ПОД НИХ ЕЩЁ СДЕЛАТЬ ПОДДЕРЖКУ АЙНДОВ И ТД

static int get_longest_size(t_offset *off, t_info *info) {
    return off->file_name + off->inode + off->bsize
           + (info->get.suffix != zaglushka);
}

static int get_file_size(t_file *file, t_info *info) {
    return file->lengths.name + file->lengths.inode
           + file->lengths.bsize + (info->get.suffix != zaglushka);
}

// НАЗВАНИ ГОВОРЯЩЕЕ ЗА СЕБЯ
static void print_n_spaces(int tabs) {        // тут короче лучше думаю не трогать принт н табс, я чёт выдумать как замутить немогу
    for (int i = 0; i < tabs; ++i)                   // print tabs depending on numb of tabs in lword and cword;
        mx_printstrlen(" ", 1, 1);
}

static void print_spaces(size_t full_len, size_t cfull_len, t_offset *of) {
    if (of->columns >= of->x + full_len + 1) {
        of->x += full_len + 1;
        print_n_spaces(full_len - cfull_len + 1);
    }
    else {
        mx_printstrlen("\n", 1, 1);
        of->x = 0;
    }
}

void mx_write_x(t_dir *dir) {
    t_file *dt = NULL;

    for (size_t i = 0; i < dir->array.size; ++i) {
        dt = mx_at(&dir->array, i);

        mx_printstrlen(dt->fields.inode, dt->lengths.inode, 1);
        mx_printstrlen(dt->fields.bsize, dt->lengths.bsize, 1);
        dir->info->print_name(dt);
        mx_printchar(dt->fields.suffix, 1);  
        if (i + 1 != dir->array.size)
            print_tabs(get_file_size(dt, dir->info),
                       get_longest_size(&dir->off, dir->info), &dir->off);
    }
}
