#include "uls.h"

// ДОДЕЛАТЬ СТРУКТУРЫ ТОГДА ИЗИ ЭТО ПЕРЕПИШУ ПОД НИХ ЕЩЁ СДЕЛАТЬ ПОДДЕРЖКУ АЙНДОВ И ТД


// ПОЛУЧИТЬ КОЛИЧЕСТВО ТАБОВ В САМОМ ДЛИННОМ СЛОВЕ

static int get_tabs(int size) {
    int count = 0;

    for (; size >= 8; size -= 8)
        ++count;
    return count;
}

static int get_data_len(t_info *info, t_dir *dir, t_file *file, bool longest) {
    if (longest)
        return dir->off.name + dir->off.inode + (dir->off.inode != 0) + dir->off.bsize + (dir->off.bsize != 0) + (info->get.suffix != mx_dummy);

    return file->lengths.name + file->lengths.inode + file->lengths.bsize + (info->get.suffix != mx_dummy);
}

// НАЗВАНИ ГОВОРЯЩЕЕ ЗА СЕБЯ
static void print_n_tabs(int tabs) {        // тут короче лучше думаю не трогать принт н табс, я чёт выдумать как замутить немогу
    for (int i = 0; i < tabs; ++i)                   // print tabs depending on numb of tabs in lword and cword;
        mx_printstrlen("\t", 1, 1);
}

static void print_tabs(t_info *info, t_dir *dir, t_file *dt) {
    int full_len_longest = get_data_len(info, dir, dt, true);
    int full_len_current = get_data_len(info, dir, dt, false);
    uint8_t tabs_cword = get_tabs(get_data_len(info, dir, dt, false));

    if (dir->off.width >= dir->off.x + dir->off.name_tabs * 16) {
        dir->off.x += dir->off.name_tabs * 8;
        print_n_tabs(full_len_longest - full_len_current ? dir->off.name_tabs - tabs_cword : 1);
    }
    else {
        mx_printstrlen("\n", 1, 1);
        dir->off.x = 0;
    }
}

void mx_write_x(t_info *info, t_dir *dir) {
    t_file *dt = NULL;

    dir->off.width = mx_winsize(info);
    dir->off.x = 0;
    dir->off.name_tabs = get_tabs(get_data_len(info, dir, NULL, true)) + 1;
    for (size_t i = 0; i < dir->array.size; ++i) {
        dt = mx_at(&dir->array, i);
        mx_printstrlen(dt->fields.inode, dt->lengths.inode, 1);
        mx_printstrlen(dt->fields.bsize, dt->lengths.bsize, 1);
        info->print_name(dt);
        mx_printstrlen(&dt->fields.suffix, dt->lengths.suffix, 1);
        if (i + 1 < dir->array.size)
            print_tabs(info, dir, dt);
    }
    mx_printstrlen("\n", 1, 1);
}
