#pragma once
#include "uls.h"

#define MX_FLAGS "ACFGRSTUacdfgilmnopqrstuvwx1"
#define MX_USAGE "usage: uls [-" MX_FLAGS "] [file ...]"

#define MX_DEF "\033[0m"        // ----------       // default
#define MX_EXE "\033[0;31m"     // ---x--x--x       // execute
#define MX_SCK "\033[0;32m"     // s---------       // socket
#define MX_FIF "\033[0;33m"     // p---------       // fifo
#define MX_DIR "\033[0;34m"     // d---------       // directory
#define MX_LNK "\033[0;35m"     // l---------       // link
#define MX_CHR "\033[34;43m"    // c---------       // char
#define MX_BLK "\033[34;46m"    // b---------       // block
#define MX_UIB "\033[30;41m"    // ---s------       // user id bit
#define MX_GIB "\033[30;46m"    // ------s---       // group id bit
#define MX_SKB "\033[30;42m"    // --------w[Tt]    // sticky bit
#define MX_NSB "\033[30;43m"    // --------w-       // not sticky bit

#define MX_HALF_YEAR 15768000
