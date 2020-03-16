# uls

### Usage:
**`./uls [-ACFGRSTUacdfgilmnopqrstuvwx1] [file ...]`**

### Flags-table:

| Flag  | Description |
|:-----:|:-:|
|**`1`**| Force output to be one entry per line |
|**`C`**| Force multi-column output |
|**`l`**| List in long format |
|**`m`**| List files across the page, separated by commas |
|**`x`**| Multi-column output is produced with entries sorted across |
| | |
|**`A`**| List all entries except for **`.`** and **`..`** |
|**`a`**| Include directory entries whose names begin with a **`.`** |
| | |
|**`F`**| Print suffix after name: **`directory/`** **`executable*`** **`link@`** **`socket=`** **`whiteout%`** **`fifo\|`**|
|**`p`**| Print suffix after name: **`directory/`** |
| | |
|**`R`**| Recursively list subdirectories encountered |
|**`d`**| Directories are listed as plain files, not recursively |
| | |
|**`S`**| Sort files by size |
|**`f`**| Output is not sorted, force listing of all entries in directory |
|**`r`**| Reverse the order of the sort |
|**`t`**| Sort by time parameter |
| | |
|**`U`**| Use time of file creation |
|**`c`**| Use time when file status was last changed |
|**`u`**| Use time of last access |
| | |
|**`T`**| Display full time: month, day, hour, minute, second, year |
|**`g`**| Suppressed owner name, force long output |
|**`i`**| Print the file's file serial number |
|**`n`**| Display user and group IDs numerically, force long output |
|**`o`**| Suppressed group, force long output |
|**`s`**| Display the number of file system blocks actually used by each file |
| | |
|**`q`**| Print character **`?`** instead of non-printable characters in file names|
|**`v`**| Force unedited printing of non-graphic characters |
|**`w`**| Force raw printing of non-printable characters |
| | |
|**`G`**| Enable colorized output |
| | |

| Unidirectional order of flag rewriting |
|:---:|
|**`t ==> S ==> f`** |
|**`R ==> d`** |
|**`l ==> n ==> g`** |
|**`l ==> n ==> o`** |
|**`C ==> m`** |
|**`x ==> m`** |
|**`A ==> a`** |
|**`A ==> f`** |

### Default flags by category

**`C` - default output to terminal**\
**`1` - default output not to terminal**\
\
**`q` - default printing name to terminal**\
**`v` - default printing name not to terminal**\
**`w` - default printing name not to terminal**
