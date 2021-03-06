#ifndef ULS_H
#define ULS_H

#include "libmx/inc/libmx.h"
#include <dirent.h>
#include <time.h>
#include <pwd.h>
#include <errno.h>
#include <grp.h>

#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/xattr.h>
#include <sys/acl.h>

#define MX_HALF_YEAR 15724800

#define MX_ISREG 0100000
#define MX_ISDIR 0040000
#define MX_ISCHR 0020000
#define MX_ISBLK 0060000
#define MX_ISFIFO 0010000
#define MX_ISLNK 0120000
#define MX_ISSOCK 0140000

#define MX_ISUID 04000
#define MX_ISGID 02000
#define MX_ISVTX 01000

#define MX_IRUSR 00400
#define MX_IWUSR 00200
#define MX_IXUSR 00100

#define MX_IRGRP 00040
#define MX_IWGRP 00020
#define MX_IXGRP 00010

#define MX_IROTH 00004
#define MX_IWOTH 00002
#define MX_IXOTH 00001

#define MX_IFMT 0170000

#define MX_MAJOR(x) ((int32_t)(((u_int32_t)(x) >> 24) & 0xff))
#define MX_MINOR(x) ((int32_t)((x) & 0xffffff))

typedef struct s_flags {
    int a;
    int f;
    int l;
    int one;
    int big_r;
    int big_a;
    int h;
    int big_t;
    int big_c;
    int big_f;
    int m;
    int p;
    int r;
    int t;
    int u;
    int c;
    int big_s;
    int o;
    int n;
}              t_flags;

typedef struct s_size {
    char *name;
    int size;
}              t_size;

typedef struct s_time {
    char *name;
    int t;
}              t_time;

struct s_size_colum {
    int nlink;
    int uid;
    int gid;
    int size;
    int maj;
    int min;
};

t_list **mx_usage_error(int argc, char **argv, char *usage_flags);
void mx_principal_printable_flag(t_flags *true_flags, char *str);
void mx_select_flags(t_flags *true_flags, char flag);
void mx_select_flags_first(t_flags *true_flags, char flag);
void mx_select_flags_second(t_flags *true_flags, char flag);
void mx_select_flags_third(t_flags *true_flags, char flag);
void mx_select_flags_fourth(t_flags *true_flags, char flag);
void mx_select_flags_fifth(t_flags *true_flags, char flag);
t_list **mx_parsing(int i, int argc, char **argv, t_flags *true_flags);
void mx_check_flags_first(t_list **parser, t_flags *true_flags);
void mx_check_flags_second(t_list **parser, t_flags *true_flags);

void mx_size_sort(t_list **names, char *dir);
void mx_time_sort(t_list **names, char *dir, t_list *flags);

void mx_uls(t_list **parser);
  void mx_for_big_r(t_list ***parser);
  void mx_no_such_file_or_dir(t_list *names);
  void mx_all_files(t_list *files, t_list *flags, int flows);
    void mx_l_flag(t_list *files, t_list *flags, char *dir);

    void mx_big_c_flag(t_list *files, t_list *flags, int ws_size, char *dir);

    void mx_one_flag(t_list *files, t_list *flags, char *dir);
    void mx_m_flag(t_list *files, t_list *flags, int ws_size, char *dir);
void mx_permission(t_list *names, int flows);
void mx_all_directory(t_list *dir, t_list *flags, int flows);

void mx_ascii_sort(t_list **l);
void mx_select_sort(t_list **names, t_list *flags, char flag, char *dir);
char mx_get_flag(t_list *flags, char *corect_flags, char default_f);
void mx_mult_colum(t_list *names, int win_size, int longest, int size_list);
void mx_r_sort(t_list **names);
char *mx_path_to_dir(char *str, char *dir);
void mx_print_for_dir(t_list *files, t_list *flags, char *dir);
void mx_print_l(t_list *files, char *str, struct s_size_colum *sc);
void mx_socets(struct stat *buff, char *files);
char mx_interceptor(void);
void mx_size_mm(struct stat *buff, struct s_size_colum *sc, char *cn);
void mx_time(struct stat *buff);

int mx_size_colum(int buf);

#endif
