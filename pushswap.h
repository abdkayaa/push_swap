#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_options
{
    int simple;
    int medium;
    int complex;
    int adaptive;
    int bench;
}   t_options;


typedef struct s_stack
{
    int *array;
    int size;
}   t_stack;

void ft_putstr_fd(char *s, int fd);
void error_exit(void);
long ft_atoi(char *num);
void ft_check_duplicates(int *stack, int size);

void init_options(t_options *opts);
int ft_strcmp(char *s1, char *s2);
int parse_flag(char *arg, t_options *opts);
void verify_strategies(t_options *opts);

#endif