#include "push_swap.h"

void    ft_print_list(t_flist *first, t_flist *second)
{
    while (first || second)
    {
        if(first)
            ft_putnbr(first->number);
        ft_putchar(' ');
        if(second)
            ft_putnbr(second->number);
        ft_putchar('\n');
        if (first)
            first = first->next;
        if (second)
            second = second->next;
    }
}
int main(int ac, char **av)
{
    t_flist *first_a;
    t_flist *first_b;
    char a;
    char b;

    a = 'a';
    b = 'b';
    first_a = get_list(av, ac, a);
    first_b = (t_flist*)malloc(sizeof(t_flist));
    first_b->next = NULL;
    //first_b = get_list(av, ac, b);
    //ft_push_back(&first_a, &first_b); /* Push b /Push a  в Данном случае из стека a в стек b*/
    //ft_swap(&first_a, first_a->next, first_b, 0); /* Function swap */
    //ft_check_sort(ac - 1, &first_a); /* Сортировка пузырьком стандартная */
    //ft_list_reverse(&first_a); /* Реверс лист Reverse rotate */
    //ft_rotate(&first_a); /* Function rotate */
    ft_swap(&first_a, first_a->next, first_b, 0);
    ft_push_back(&first_a, &first_b);
    ft_print_list(first_a, first_b); /* распечатка обоих листов*/
    
    //ft_print_list(first_a);
    return (0);
}