/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 20:10:48 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/06/24 20:13:34 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_analyze_operation(t_swap *swap)
{
	swap->pa = 1;
	while (swap->ra != 0 && swap->rb != 0)
	{
		swap->ra--;
		swap->rb--;
		swap->rr++;
	}
	while (swap->rra != 0 && swap->rrb != 0)
	{
		swap->rra--;
		swap->rrb--;
		swap->rrr++;
	}
}

void	ft_write_index_res(t_push *push, t_swap *swap, int i)
{
	if (push->fl == 0)
	{
		push->res = swap->ra + swap->rb + swap->rr + swap->rra +
		swap->rrb + swap->rrr;
		push->index = i;
		push->fl = 1;
	}
	else if (push->fl == 1 && ((push->res > swap->ra + swap->rb +
	swap->rr + swap->rra + swap->rrb + swap->rrr) || (push->size_b == 1)))
	{
		push->res = swap->ra + swap->rb + swap->rr + swap->rra +
		swap->rrb + swap->rrr;
		push->index = i;
	}
}

void	ft_counter(t_push *push, t_swap *swap, int i)
{
	int	j;
	int	tmp;

	j = 0;
	tmp = push->stack_b[i];
	if (i < push->size_b - i)
		swap->rb = i;
	else
		swap->rrb = push->size_b - i;
	while (j + 1 < push->size_a)
	{
		if ((push->stack_a[j] < tmp) && (push->stack_a[j + 1] > tmp))
		{
			if (j + 1 < push->size_a - (j + 1))
				swap->ra = j + 1;
			else
				swap->rra = push->size_a - (j + 1);
			break ;
		}
		else
			j++;
	}
	ft_analyze_operation(swap);
}

void	ft_count_operation(t_push *push)
{
	int		i;
	t_swap	*swap;

	i = 0;
	if (!(swap = (t_swap *)malloc(sizeof(t_swap))))
		ft_out();
	while (i < push->size_b)
	{
		ft_initialization_swap(swap);
		ft_counter(push, swap, i);
		ft_write_index_res(push, swap, i);
		i++;
	}
	ft_initialization_swap(swap);
	ft_sort_stack(push, swap);
	free(swap);
}

void	ft_sort_three_item(t_push *push)
{
	ft_printf("sa\n");
	if (push->stack_a[1] == push->min)
	{
		swap_operations(push, 'a');
		return ;
	}
	else
		swap_operations(push, 'a');
	if (push->stack_a[0] == push->min)
	{
		rotate_operations(push, 'a');
		ft_printf("ra\n");
	}
	else if (push->stack_a[2] == push->min)
	{
		reverse_rotate_operations(push, 'a');
		ft_printf("rra\n");
	}
}
