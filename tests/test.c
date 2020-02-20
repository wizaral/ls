#include "uls.h"
#include <stdio.h>

int main() {
    t_vector *v = mx_create_vector(0, sizeof(struct passwd *));
    char *cdir = "/Users/oafanasiev/Desktop/lsgit/tests/";
    DIR *dir = opendir(cdir);

    struct dirent *file = NULL;
    struct passwd *pass = NULL;
    struct group *grp = NULL;
    struct stat ___stat;
    char *name = NULL;

    if (v && dir) {
        for (file = readdir(dir); file; file = readdir(dir)) {
            printf(":%s: ", file->d_name);
            name = mx_strjoin(cdir, file->d_name);
            lstat(name, &___stat);

            pass = getpwuid(___stat.st_uid);
            grp = getgrgid(___stat.st_gid);

            if (pass)
                printf(":%s: ", pass->pw_name);

            if (grp)
                printf(":%s:\n", grp->gr_name);
            else
                printf(":%i:\n", ___stat.st_gid);
            // mx_push_backward(v, &pass);

            free(name);
        }
        closedir(dir);

        printf("==========================================================\n");

        // for (size_t i = 0; i < v->size; ++i) {
        //     pass = *(struct passwd **)mx_at(v, i);
        //     printf(":%s:%s:\n", pass->pw_name, pass->pw_class);
        // }
    }
    else {
        perror(NULL);
    }
    mx_delete_vector(v);
    system("leaks -q a.out");
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
