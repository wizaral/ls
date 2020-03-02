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

#define MX_ISVTX        0001000
#define MX_IRUSR        0000400
#define MX_IWUSR        0000200
#define MX_IXUSR        0000100
#define MX_IRGRP        0000040
#define MX_IWGRP        0000020
#define MX_IXGRP        0000010
#define MX_IROTH        0000004
#define MX_IWOTH        0000002
#define MX_IXOTH        0000001
#define MX_ISTXT        MX_ISVTX

#define MX_HALF_YEAR 15768000
