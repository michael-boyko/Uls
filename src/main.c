#include "uls.h"


int main(int argc, char *argv[]) {
    t_list **parser = NULL;
    char *usage_flags = mx_strnew(20);

    usage_flags = "ACFRSTacfhlmnoprtu1";
    parser = mx_usage_error(argc, argv, usage_flags);
    mx_uls(parser);

    // system("leaks -q  uls");

    return 0;
}
