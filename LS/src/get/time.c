#include "uls.h"

void mx_time_full(t_dir *dir, t_file *file, t_stat *st) {
    char *temp = ctime(&file->time.tv_sec);

    ++temp;
    ++dir;
    ++st;
}

void mx_time_short(t_dir *dir, t_file *file, t_stat *st) {
    char *temp = ctime(&file->time.tv_sec);
    time_t now = time(NULL);

    ++temp;
    ++now;
    ++dir;
    ++st;
}

// void mx_print_time(time_t *t) {
//     char *temp_time = ctime(t);
//     char *result = mx_strnew(12);
//     time_t now = time(NULL);
//     long half_year = 15778463;

//     if ((now - half_year) > *t || now < *t) {
//         result = mx_strncpy(result, temp_time + 4, 6);
//         mx_strcpy(result + 6, "  ");
//         mx_strncpy(result + 8, temp_time + 20, 4);
//     }
//     else
//         result = mx_strncpy(result, temp_time + 4, 12);
//     mx_printstr(result);
//     mx_printchar(' ');
//     mx_strdel(&result);
// }


// static void strtime(char *tmp, t_const *cnst, t_data *data) {
//     time_t now = time(NULL);
//     char *new = NULL;

//     new = data->flags[6] == 1 ? mx_strnew(20) : mx_strnew(12);
//     tmp += 4;
//     if (data->flags[6])
//         mx_strncpy(new, tmp, 20);
//     else if ((now - cnst->time) < MX_HALF_YEAR)
//         mx_strncpy(new, tmp, 12);
//     else {
//         mx_strncpy(new, tmp, 7);
//         tmp += 15;
//         mx_strcat(new, tmp);
//         new[12] = '\0';
//     }
//     cnst->strtime = new;
// }

// void mx_get_time(struct stat st, t_const *cnst, t_data *data){
//     char *tmp = NULL;

//     if (data->flags[13]) {
//         cnst->nsec = st.st_atimespec.tv_nsec;
//         cnst->time = st.st_atime;
//     }
//     else if (data->flags[22]) {
//         cnst->nsec = st.st_ctimespec.tv_nsec;
//         cnst->time = st.st_ctime;
//     }
//     else {
//         cnst->nsec = st.st_mtimespec.tv_nsec;
//         cnst->time = st.st_mtime;
//     }
//     tmp = ctime(&cnst->time);
//     strtime(tmp, cnst, data);
// }
