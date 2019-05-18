#include "push_swap.h"

/*int ft_check_ascend(t_flist *list, char **str)
{
    
}*/
int     ft_check_int(t_flist **one, t_flist *second)
{
    return ((*one)->number - second->number);
}

void    ft_check_sort(int number, t_flist **mas)
{
    int i;
    int j;
    t_flist *new;
    t_flist *start;

    i = 1;
    j = 1;
    start= (t_flist*)malloc(sizeof(t_flist));
    start->number = (*mas)->number;
    start->next = NULL;
    while (j < number)
    {
        i = 1;
        while (i < number)
         {
            new = (*mas)->next;
             if (ft_check_int(mas, new) > 0)
             {
                 start = ft_swap(mas, new, start, i);
             }
            else if (i == 1)
                start->next = (*mas)->next;
            i++;
            *mas = (*mas)->next;
         }
        *mas = start;
        j++;
    }
}

t_flist    *ft_swap(t_flist **first, t_flist *new, t_flist *start, int i)
{
    t_flist *final;
    t_flist *new2;
    t_flist *begin;

    
    new2 = new;
    (*first)->next = (*first)->next->next;
    new2->next = NULL;
    
    new2->next = *first;
    final = new2;
    *first = final;
    if (i> 1)
    {
        begin = start;
         while (i > 2)
             {
             begin = begin->next;
             i--;
            }
            begin->next = final;
    }
    else
        start = *first;
    return (start);
}   

void    ft_push_back(t_flist **first, t_flist **second)
{
    t_flist *other;

    other = (t_flist*)malloc(sizeof(t_flist));
    other->number = (*first)->number;
    other->next = *second;
    *second = other;
    *first = (*first)->next;
}
int		ft_list_size(t_flist *begin_list)
{
	int		i;

	i = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		++i;
	}
	return (i);
}
void    ft_reverse_rotate(t_flist **first)
{
    t_flist *one;
    t_flist *final;
    t_flist *second;
    
    int j;

    one = *first;
    final = *first;

    j = ft_list_size(one);


    while (final->next)
    {
        final = final->next;
    }
    second = final;
    final->next = one;
    while (j > 0)
    {
        if (j - 1 == 0)
            {
                final->next = NULL;
                break;
            }
        final = final->next;
        j--;
    }
    *first = second;
    
}

void    ft_rotate(t_flist **first)
{
    t_flist *one;
    t_flist *final;

    one = *first;
    final = *first;
    *first = (*first)->next;
    while (final->next)
    {
        final = final->next;
    }
    final->next = one;
    one->next = NULL;
}