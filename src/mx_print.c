#include "uls.h"

// void mx_print_w_flags(t_vector *file_vect) {
//     int count = 0;
//     t_dir *file = file_vect->arr;

//     for (t_ull i = 0; i < file_vect->size; i++) {
//         if (mx_strncmp(file[i].d_name, ".", 1) != 0) {
//             if (count != 4) {
//                 if (count > 0)
//                     printf("\t%s", file[i].d_name);
//                 else if (count == 0)
//                     printf( "%s\t", file[i].d_name);
//                 count++;
//             }
//             else {
//                 printf("\t%s\n", file[i].d_name);
//                 count = 0;
//             }
//         }
//     }
// }

// void basic_print(t_vector *file_vect, t_info info) {
// 	int j;
// 	int sub_r;
// 	int tab_len = 0;

// 	for (int i = 0; i < num_of_lines; i++) {
// 		j = 0;
// 		sub_r = 0;
// 		for (t_vector *file_vect = file_vect->arr; tmp; tmp = tmp->next, j++) {
// 			if ((j + num_of_lines - i) % num_of_lines == 0) {
// 				mx_printstr(tmp->data);
// 				if (sub_r + num_of_lines < info->num_of_sub) {
// 					tab_len = info->max_sub_len - mx_strlen(tmp->data);
// 					print_tabs(tab_len + (8 - (info->max_sub_len % 8)));
// 				}
// 			}
// 			++sub_r;
// 		}
// 		mx_printchar('\n');
// 	}
// }

// static void print_tabs(int n) {
// 	for (int i = 0; i < n; i++)
// 		write(1, " ", 1);
// }

void basic_print(t_vector *file_vect, t_info *info) {
    t_data *data;
    if (info) {};
    printf("total %llu\n", info->total);
    for (t_ull i = 0; i < file_vect->size; i++) {
        data = mx_at(file_vect, i);
        printf("%s %s %s %s %s %s %s\n", data->access, data->links, data->login, data->grp, data->size, data->time, data->ent->d_name); 
    }
}

// void basic_print(t_vector *file_vect, t_info *info) {
//     int j = 0;
//     int sub_r;
//     int tab_len = 0;

//     for (t_ull i = 0; i < info->lines; ++i) {
//         j = 0;
//         sub_r = 0;
//         for (t_ull t = 0; t < file_vect->size; ++t) {
//             ++j;
//             if ((j + info->lines - i) % info->lines == 0) {
//                 mx_printstr(((t_dir *)file_vect->arr)[t].d_name, 1);
//                 if (sub_r + info->lines < info->num_of_sub) {
//                     tab_len = info->max_len - mx_strlen(((t_dir *)file_vect->arr)[t].d_name);
//                     print_tabs(tab_len + (8 - (info->max_len % 8)));
//                 }
//             }
//             ++sub_r;
//         }
//         mx_printchar('\n', 1);
//     }
// }
