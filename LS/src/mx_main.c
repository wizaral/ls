#include "uls.h"
#include <stdio.h>

// struct s_info {
    // t_vector arg_dir; // Вектор куда закидываются папки которые явлсяются аргументами
    // t_vector file_vect // Вектор всех файлов в папке для вывода.

//     // Здесь хочу иметь указатель на функцию вывода 
//     // Мб ещё одну структуру сюда в которой будут данные для вывода (макс длина слова и тд)
// } t_info;

typedef struct s_data {
    struct stat st;
    struct dirent *dr;
} t_data;

typedef struct s_offsets {
    int longest_word;
    int wsize;
    int cnum;
} t_offsets;

void get_wsize(t_offsets *offsets) {
    struct ttysize ts;

    ioctl(1, TIOCGSIZE, &ts);
    offsets->cnum = ts.ts_cols;
    offsets->wsize = ts.ts_xxx;
}

t_vector *get_files(char *direct) {
    DIR *dir;
    t_vector *file_vect = mx_create_vector(0, sizeof(t_data *));
    t_data *dt = (t_data *)malloc(sizeof(t_data));

    if ((dir = opendir(direct)) != NULL) {
        while ((dt->dr = readdir(dir)) != NULL) {
            lstat(mx_strjoin(mx_strjoin(direct, "/"), dt->dr->d_name), &dt->st);
            mx_push_backward(file_vect, &dt);
            dt = (t_data *)malloc(sizeof(t_data));
        }
    }
    closedir(dir);
    
    return file_vect;
}

int main(int argc, char **argv) {
    if (argc) {}
    t_vector *v = get_files(argv[1]);
    t_offsets *offsets = malloc(sizeof(t_offsets));
    get_wsize(offsets);

    for (size_t i = 0; i < v->size; ++i) {
        t_data **dt = mx_at(v, i);
        
        printf("%s\t", (*dt)->dr->d_name);
    }
}


// старое

int main(int argc, char **argv) {
    // Аргументы закинуть в arg_dir посортировать и отправить на парсинг
    // Там если аргумент не папка он будет из вектора убиратся
    mx_parse(argc, argv); // должно быть 3 параметра 1 структура куда всё вбивать
    // Здесь чекнуть на то что папка открывается если нет то говорим permission denied
    // Здесь начинается сама функция юлса скорее всего
}