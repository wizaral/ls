#include "uls.h"

uint16_t mx_get_ws(t_info *info) {
    if (info->output_dst == 0) {
        struct winsize ws;
        int fd = open("/dev/tty", O_RDWR);

        ioctl(fd, TIOCGWINSZ, &ws);
        close(fd);
        return ws.ws_col;
    }
    return 79;
}
