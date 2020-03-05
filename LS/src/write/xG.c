#include "uls.h"

// // ДОДЕЛАТЬ СТРУКТУРЫ ТОГДА ИЗИ ЭТО ПЕРЕПИШУ ПОД НИХ ЕЩЁ СДЕЛАТЬ ПОДДЕРЖКУ АЙНДОВ И ТД

static int get_data_len(t_info *info, t_dir *dir, t_file *file, bool longest) {
    if (longest)
        return dir->off.name + dir->off.inode + (dir->off.inode != 0) + dir->off.bsize
             + (dir->off.bsize != 0) + (info->get.suffix != mx_dummy);

    return file->lengths.name
         + file->lengths.inode + (file->lengths.inode != 0)
         + file->lengths.bsize + (file->lengths.bsize != 0)
         + (info->get.suffix != mx_dummy);
}

// НАЗВАНИ ГОВОРЯЩЕЕ ЗА СЕБЯ
static void print_n_spaces(int spaces) {        // тут короче лучше думаю не трогать принт н табс, я чёт выдумать как замутить немогу
    for (int i = 0; i < spaces; ++i)                   // print tabs depending on numb of tabs in lword and cword;
        mx_printstrlen(" ", 1, 1);
}

static void print_spaces(size_t full_len, size_t cfull_len, t_offset *of) {
    if (of->width > of->x + full_len + full_len) {
        of->x += full_len + 2;
        print_n_spaces(full_len - cfull_len + 1);
    }
    else {
        mx_printstrlen("\n", 1, 1);
        of->x = 0;
    }
}

void mx_write_xG(t_info *info, t_dir *dir) {
    t_file *dt = NULL;

    dir->off.width = mx_winsize(info);
    dir->off.x = 0;
    dir->off.name_tabs = get_data_len(info, dir, dt, true) + 1;
    for (size_t i = 0; i < dir->array.size; ++i) {
        dt = mx_at(&dir->array, i);
        // print_inode(dir, dt);
        mx_printstrlen(dt->fields.inode, dt->lengths.inode, 1);
        mx_printstrlen(dt->fields.bsize, dt->lengths.bsize, 1);
        info->print_name(dt);
        mx_printstrlen(&dt->fields.suffix, dt->lengths.suffix, 1);  
        if (i + 1 < dir->array.size)
            print_spaces(get_data_len(info, dir, dt, true),
                         get_data_len(info, dir, dt, false), &dir->off);
    }
    mx_printstrlen("\n", 1, 1);
}
