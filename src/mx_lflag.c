#include "uls.h"

static char *get_login(uid_t st_uid) {
    char *user = (char *)malloc(256);
    struct passwd *pw = getpwuid(st_uid);

    if (pw == NULL)
        user = mx_itoa(st_uid);
    else
        mx_strcpy(user, pw->pw_name);
    return user;
}

static char *get_gname(gid_t st_gid) {
    char *grpname = (char *)malloc(256);
    struct group *grp = getgrgid(st_gid);

    if (grp == NULL)
        grpname = mx_itoa(st_gid);
    else
        mx_strcpy(grpname, grp->gr_name);
    return grpname;
}

void mx_advanced_permissions_check(t_vector *vec, t_info *info) {
    acl_t acl;
    t_data *data = NULL;
    struct stat st;
    

    for (t_ull i = 0; i < vec->size; i++) {
        data = (t_data *)mx_at(vec, i);
        stat(data->path, &st);
        acl = acl_get_file(data->path, ACL_TYPE_EXTENDED);
        if (listxattr(data->path, NULL, 0, XATTR_NOFOLLOW) > 0)
            data->access[10] = '@';
        if (acl) {
            mx_strcat(data->access, "+");
            acl_free(acl);
        }
        data->login = get_login(st.st_uid);
        data->links = mx_itoa(st.st_nlink);
        data->grp = get_gname(st.st_gid);
        data->time = mx_strndup(((ctime)(&st.st_mtimespec.tv_sec) + 4), 12);
        data->size = mx_sym_num(data->access[0], st); // Simple -l flag realization
        // float buf = mx_atoll(mx_sym_num(data->access[0], st));
        // int unit = 0;
        // while (buf > 1) {
        //     buf /= 1024;
        //     ++unit;
        // }
        // char *buff = mx_itoa(buf);
        // printf("%s", buff);
        // mx_strcat(data->size, mx_strcat(buff, "K"));
        info->total += st.st_blocks;
    }
}

static inline void basic_perm(t_data *data, struct stat buff) {
    char *str = NULL;
    str = mx_strnew(10);

    str[0] = S_ISDIR(buff.st_mode) ? 'd' : '-';
    str[0] = S_ISLNK(buff.st_mode) ? 'l' : str[0];
    str[0] = S_ISCHR(buff.st_mode) ? 'c' : str[0];
    str[0] = S_ISBLK(buff.st_mode) ? 'b' : str[0];
    str[1] = buff.st_mode & S_IRUSR ? 'r' : '-';
    str[2] = buff.st_mode & S_IWUSR ? 'w' : '-';
    str[3] = buff.st_mode & S_IXUSR ? 'x' : '-';
    str[4] = buff.st_mode & S_IRGRP ? 'r' : '-';
    str[5] = buff.st_mode & S_IWGRP ? 'w' : '-';
    str[6] = buff.st_mode & S_IXGRP ? 'x' : '-';
    str[7] = buff.st_mode & S_IROTH ? 'r' : '-';
    str[8] = buff.st_mode & S_IWOTH ? 'w' : '-';
    str[9] = buff.st_mode & S_IXOTH ? 'x' : '-';
    buff.st_mode & S_ISTXT ? str[9] = 't' : 0;
    data->access = mx_strdup(str);
    free(str);
}

void mx_basic_permissions(t_vector *vec) {
    t_data *data = NULL;
    struct stat buff;

    for (t_ull i = 0; i < vec->size; i++) {
        data = (t_data *)mx_at(vec, i);
        lstat(data->path, &buff);
        basic_perm(data, buff);
    }
}

void mx_l_flag(t_vector *vec, t_info *info) {
    mx_basic_permissions(vec);
    mx_advanced_permissions_check(vec, info);
}
