#include "push_swap.h"

/*static char *read_file(int fd)
{
    char * str;
    char *buf;
    int ret;

    str =(char *)malloc(sizeof(char));
    str[0] = '\0';
    buf = (char*)malloc (sizeof(char) * (BUFF_SIZE + 1));
    while ((ret = read(fd, buf, BUFF_SIZE)))
    {
        buf[ret] = '\0';
        str = ft_strjoin(str, buf);
    }
    free(buf);
    return (str);
}
*/
static t_flist *ft_create_list(char *str, char num)
{
    t_flist *begin;
    
    begin = (t_flist*)malloc(sizeof(t_flist));
    if (num == 'a')
        begin->number = ft_atoi(str);
    return (begin);
}

t_flist *get_list(char **av, int ac, char num)
{
    t_flist *new;
    t_flist *list;
    t_flist *start;
    int i;

    i = 2;
    if (ac == 1)
        {
            ft_putchar('\n');
            new = NULL;
        }
    else
    {
        new = ft_create_list(av[1], num);
        new->next = NULL;
        start = new;
        while (i < ac)
         {
            list = ft_create_list(av[i], num);
            list->next = NULL;
            start->next = list;
            start = list;
            i++;
         }
    }
    return (new);
}