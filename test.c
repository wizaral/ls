#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>

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
    DIR *dir = opendir("/");
    char *name;
    struct stat _stat;
    struct dirent *file = readdir(dir);

    while (file) {
        name = strjoin("/", file->d_name);
        stat(name, &_stat);
        // printf("%s:%u:\n", fflagstostr(_stat.st_flags), _stat.st_flags);
        printf("%s\t:\t%llu\n", name, _stat.st_ino);
        file = readdir(dir);
        free(name);
    }
    closedir(dir);
}
