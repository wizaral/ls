#include "uls.h"

int mx_get_data_len(t_info *info, t_dir *dir, t_file *file, bool longest) {
    if (longest)
        return dir->off.name + mx_get_inode_bsize_len(&dir->off)
             + (info->get.suffix != mx_dummy);

    return file->lengths.name + mx_get_inode_bsize_len(&dir->off) 
         + file->lengths.suffix;
}

char *mx_get_file_name(char *av) {
    for (char *temp = mx_strchr(av, '/'); temp; temp = mx_strchr(av, '/'))
        av = temp + 1;
    return av;
}
