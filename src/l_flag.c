#include "uls.h"

int mx_size_colum(int buf) { // Нужно сделать глобальной
    int size = 1;

    while (buf / 10 > 0) {
        size++;
        buf /= 10;
    }
    return size;
}

static void size_colum(struct s_size_colum *sc, t_list *files, char *dir) {
    char *str = NULL;
    struct stat buff;
    // struct passwd *pw;
    // struct group *gr;

    while (files != NULL) {
        if (dir != NULL)
            str = mx_path_to_dir(files->data, dir);
        else
            str = files->data;
        lstat(str, &buff);
        if (sc->nlink < mx_size_colum(buff.st_nlink))
            sc->nlink = mx_size_colum(buff.st_nlink);
        if (sc->size < mx_size_colum(buff.st_size))
            sc->size = mx_size_colum(buff.st_size);
        files = files->next;
    }
}

void mx_l_flag(t_list *files, t_list *flags, char *dir) {
    char *str = NULL;
    struct s_size_colum sc = {0, 0, 0, 0};

    size_colum(&sc, files, dir);
    // printf("%d\n", sc.nlink);
    mx_select_sort(&files, flags, mx_get_flag(flags, "ftS", 'C'), dir);
    if (mx_get_flag(flags, "r", 'C') == 'r')
        mx_r_sort(&files);
    while (files != NULL) {
        if (dir != NULL)
            str = mx_path_to_dir(files->data, dir);
        else
            str = files->data;
        mx_print_l(files, str, &sc);
        files = files->next;
    }
}
