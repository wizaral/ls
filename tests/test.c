#include "uls.h"
#include <stdio.h>

typedef struct s_ {
    struct dirent *file;
    struct passwd *pass;
    struct group *grp;
} t_;

int main() {
    t_vector *v = mx_create_vector(0, sizeof(t_));
    // char *cdir = "/Users/oafanasiev/Desktop/lsgit/tests/";
    char *cdir = "/dev/";
    DIR *dir = opendir(cdir);

    struct dirent *file = NULL;
    struct passwd *pass = NULL;
    struct group *grp = NULL;
    struct stat ___stat;
    char *name = NULL;
    t_ temp;
    t_ *tt;

    if (v && dir) {
        for (file = readdir(dir); file; file = readdir(dir)) {
            name = mx_strjoin(cdir, file->d_name);
            lstat(name, &___stat);

            pass = getpwuid(___stat.st_uid);
            grp = getgrgid(___stat.st_gid);

            // if (pass)
            //     printf(":%s", pass->pw_name);
            // else
            //     printf(":FUCK");

            // if (grp)
            //     printf(":%s", grp->gr_name);
            // else
            //     printf(":%i", ___stat.st_gid);
            temp.file = file;
            temp.pass = pass;
            temp.grp = grp;

            mx_push_backward(v, &temp);
            printf(":%s:\n", file->d_name);

            free(name);
        }
        closedir(dir);

        printf("==========================================================\n");

        for (size_t i = 0; i < v->size; ++i) {
            tt = mx_at(v, i);

            // if (tt->pass)
            //     printf(":%s", tt->pass->pw_name);
            // else
            //     printf(":FUCK");

            // if (tt->grp)
            //     printf(":%s", tt->grp->gr_name);
            // else
            //     printf(":SHIT");

            // printf(":%s:\n", tt->file->d_name);
            // // printf(":%s:%s:%s:\n", tt->pass->pw_name, tt->grp->gr_name, tt->file->d_name);
        }
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
