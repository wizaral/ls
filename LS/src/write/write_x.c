#include "uls.h"

// ДОДЕЛАТЬ СТРУКТУРЫ ТОГДА ИЗИ ЭТО ПЕРЕПИШУ ПОД НИХ ЕЩЁ СДЕЛАТЬ ПОДДЕРЖКУ АЙНДОВ И ТД


// ПОЛУЧИТЬ КОЛИЧЕСТВО ТАБОВ В САМОМ ДЛИННОМ СЛОВЕ
static int get_tabsin_file(t_file *file, t_info *info) {
    int count = 0;
    int file_tabs = file->lengths.name + file->lengths.inode
                  + file->lengths.bsize + (info->get.suffix != zaglushka);

    for (; file_tabs >= 8; file_tabs -= 8)
        ++count;
    return count;
}

// НАЗВАНИ ГОВОРЯЩЕЕ ЗА СЕБЯ
static void print_n_tabs(int tabs) {        // тут короче лучше думаю не трогать принт н табс, я чёт выдумать как замутить немогу
    for (int i = 0; i < tabs; ++i)                   // print tabs depending on numb of tabs in lword and cword;
        mx_printstr("\t", 1);
}

static void print_tabs(size_t lword, size_t cword, t_offset *of) {
    uint8_t tabs_cword = get_tabsin_word(cword);

    if (of->columns >= of->x + of->file_name_tabs * 16) {
        of->x += of->file_name_tabs * 8;
        print_n_tabs(lword - cword ? of->file_name_tabs - tabs_cword : 1);
    }
    else {
        mx_print_str("\n", 1);
        of->x = 0;
    }
}

int get_data_len(t_dir *dir, t_file *file, bool longest) {
    if (longest)
        return dir->off.file_name + dir->off.inode + dir->off.bsize +
               (dir->info->get.suffix != zaglushka);

    return file->lengths.name + file->lengths.inode + file->lengths.bsize 
        + (dir->info->get.suffix != zaglushka);
}

void mx_write_x(t_dir *dir) {
    t_file *dt = NULL;
    int full_len_longest;
    int full_len_current;

    for (size_t i = 0; i < dir->array.size; ++i) {
        dt = mx_at(&dir->array, i);
        full_len_current = get_data_len(dt, dir->info, false);
        full_len_longest = get_data_len(dt, dir->info, true);

        mx_printstrlen(dt->fields.inode, dt->lengths.inode, 1);
        mx_printstrlen(dt->fields.bsize, dt->lengths.bsize, 1);
        dir->info->print_name(dt);
        mx_printchar(dt->fields.suffix, 1);  
        if (i + 1 != dir->array.size)
            print_tabs(full_len_longest, full_len_current, &dir->off);
    }
}
