#include "uls.h"

uint16_t mx_get_ws() {
    struct winsize ws;
    int fd = open("/dev/tty", O_RDWR);

    ioctl(fd, TIOCGWINSZ, &ws);
    close(fd);
    return ws.ws_col;
}
