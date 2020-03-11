#include "uls.h"

size_t mx_get_inode_bsize_len(t_offset *off) {
    return off->inode + off->bsize + (off->inode > 0) + (off->bsize > 0);
}

void mx_make_inode_bsize(t_offset *off, char *str, t_printable *print,
                         t_lengths *len) {
    mx_memcpy(str + off->inode - len->inode, print->inode, len->inode);
    mx_memcpy(str + off->inode + (off->inode > 0) + off->bsize - len->bsize,
                print->bsize, len->bsize);
}
