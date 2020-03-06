#include "uls.h"

uint16_t mx_winsize(t_info *info) {
    if (info->output_dst == 0) {
        int fd = open("/dev/tty", O_RDWR);
        struct winsize ws;

        ioctl(fd, TIOCGWINSZ, &ws);
        close(fd);
        return ws.ws_col;
    }
    return 80;
}
