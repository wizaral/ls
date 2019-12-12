#include "libmx.h"

t_ll mx_get_file_length(const char *filename) {
    int stream = open(filename, 0);
    t_ll length = 0;

    for (char buffer; read(stream, &buffer, 1) > 0; ++length);

    close(stream);
    return stream >= 0 ? length : -1;
}
