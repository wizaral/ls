#pragma once
#include "uls.h"

#define MX_USAGE "usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]"
#define MX_FLAGS "ACFGORSTU@acefghilmnpqrstuvwx1"

#define MX_DEFAULT      "\033[0m"           // NO COLOR
#define MX_EXECUTE      "\033[0;31m"        // --x--x--x
#define MX_SOCKET       "\033[0;32m"        // SOCKET
#define MX_PIPE         "\033[0;33m"        // PIPE
#define MX_DIR          "\033[0;34m"        // DIR
#define MX_LINK         "\033[0;35m"        // LINK
#define MX_BLOCK        "\033[34;46m"       // BLOCK
#define MX_CHAR         "\033[34;43m"       // CHARACTER
#define MX_UIDBIT       "\033[30;41m"       // --s------ 1
#define MX_GIDBIT       "\033[30;46m"       // -----s--- 2
#define MX_STICKYBIT    "\033[30;42m"       // -------wT(t)
#define MX_NOTSTICKYBIT "\033[30;43m"       // -------w-

#define MX_HALF_YEAR 15768000
