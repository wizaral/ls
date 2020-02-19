#include <dirent.h>
#include <errno.h>
#include <grp.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/acl.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/xattr.h>
#include <time.h>
#include <unistd.h>

char *strnew(const int size) {
    char *ptr = NULL;

    if (size >= 0 && (ptr = (char *)malloc(size + 1)))
        for (int i = 0; i <= size; ++i)
            ptr[i] = '\0';
    return ptr;
}

char *strjoin(char const *s1, char const *s2) {
    if (s1 && s2) {
        char *str = strnew(strlen(s1) + strlen(s2));
        return str ? strcat(strcat(str, s1), s2) : NULL;
    }
    return (s1 || s2) ? (s1 ? strdup(s1) : strdup(s2)) : NULL;
}

int main() {
    DIR *dir = opendir("//////////////");
    struct dirent *file = readdir(dir);

    while (file) {
        printf("%s\n", file->d_name);
        file = readdir(dir);
    }
    closedir(dir);
}

// int main() {
//     char *name = "/tmp";

//     struct stat st1;
//     struct stat st2;

//     stat(name, &st1);
//     lstat(name, &st2);

//     if (S_ISDIR(st1.st_mode))
//         printf("d1\n");
//     if (S_ISDIR(st2.st_mode))
//         printf("d2\n");
//     if (S_ISLNK(st1.st_mode))
//         printf("l1\n");
//     if (S_ISLNK(st2.st_mode))
//         printf("l2\n");
// }
