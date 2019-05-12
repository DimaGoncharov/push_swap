#include "push_swap.h"

void    ft_print_list(t_flist *first)
{
    while (first)
    {
        ft_putnbr(first->number);
        ft_putchar('\n');
        //ft_putnbr(first->b);
        //ft_putchar('\n');
        first = first->next;
    }
}
int main(int ac, char **av)
{
    t_flist *first_a;
    t_flist *first_b;
    char **str;
    char a;
    char b;

    str = (char **)malloc(sizeof(char *) * 20);
    //int fd;
    
    //ac = 2;
    /*if ((fd = open(av[1], O_RDONLY)) < 0)
    {
        ft_putendl("Error");
        return (-1);
    }*/
    a = 'a';
    b = 'b';
    first_a = get_list(av, ac, a);
    first_b = get_list(av, ac, b);
    //ft_swap_a(&first_a, &first_a, 2);
    ft_check_sort(ac - 1, &first_a);
    //ft_swap_a(&first_a);
    //ft_list_reverse(&first_a);
    //ft_swap_b(&first_b);
    //if (ft_check_ascend(first, &str) == 1)
    //    ft_print_commands(str);
   // else
    //    write(1, "KO\n", 3);
    ft_print_list(first_a);
    return (0);
}