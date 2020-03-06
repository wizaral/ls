#pragma once
#include "uls.h"

#define MX_FLAGS "ABCFGORSTU@abcefghilmnpqrstuvwx1"
#define MX_USAGE "usage: uls [-"MX_FLAGS"] [file ...]"
#define MX_USAGE_OLD "usage: uls [-ABCFGORSTU@abcefghilmnpqrstuvwx1] [file ...]"

#define MX_DEFAULT "\033[0m"            // NO COLOR
#define MX_EXECUTE "\033[0;31m"         // --x------ -----x--- --------x
#define MX_SOCKET "\033[0;32m"
#define MX_PIPE "\033[0;33m"
#define MX_DIR "\033[0;34m"
#define MX_LINK "\033[0;35m"
#define MX_CHAR "\033[34;43m"
#define MX_BLOCK "\033[34;46m"
#define MX_UIDBIT "\033[30;41m"         // --s------
#define MX_GIDBIT "\033[30;46m"         // -----s---
#define MX_STICKYBIT "\033[30;42m"      // -------wT -------wt
#define MX_NOTSTICKYBIT "\033[30;43m"   // -------w-

#define MX_HALF_YEAR 15768000
