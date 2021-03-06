#include "uls.h"

static void get_size(t_list **names, int list_size, char *dir) {
    struct stat buff;
    t_size *with_s = malloc(sizeof(t_size) * list_size);
    char *str = NULL;

    for (int i = 0; i < list_size; i++) {
        if (dir != NULL)
            str = mx_path_to_dir((*names)->data, dir);
        else
            str = (*names)->data;
        lstat(str, &buff);
        with_s[i].name = (*names)->data;
        with_s[i].size = buff.st_size;
        mx_pop_front(names);
        mx_push_back(names, &with_s[i]);
    }
}

void mx_size_sort(t_list **names, char *dir) {
    t_size *tmp = NULL;
    t_list *list = *names;
    int list_size = mx_list_size(*names);

    get_size(names, list_size, dir);
    for (t_list *i = list; i->next != NULL; i = i->next) {
        for (t_list *j = list; j->next != NULL; j = j->next) {
            if (((t_size *)(j)->data)->size < ((t_size *)(j)->next->data)->size) {
                tmp = j->data;
                j->data = j->next->data;
                j->next->data = tmp;
            }
        }
    }
   	while (list_size > 0) {
        mx_push_back(names, ((t_size *)(*names)->data)->name);
        mx_pop_front(names);
        list_size--;
    }
}
