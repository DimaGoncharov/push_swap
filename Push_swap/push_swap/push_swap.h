#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define BUFF_SIZE 15

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "../libft/libft/libft.h"

typedef struct      s_flist
{
    int             number;
    struct s_flist  *next;
}                  t_flist;

t_flist *get_list(char **av, int ac, char num);
t_flist    *ft_swap(t_flist **first, t_flist *new, t_flist *start, int i);
void ft_list_reverse(t_flist **begin_list);
void    ft_check_sort(int number, t_flist **mas);
void    ft_push_back(t_flist **first, t_flist **second);
void    ft_rotate(t_flist **first);

#endif