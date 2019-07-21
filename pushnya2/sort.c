/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 19:37:06 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/06/24 19:37:09 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_do_rotate(t_push *push, t_swap *swap)
{
	while (swap->ra > 0)
	{
		ft_printf("ra\n");
		rotate_operations(push, 'a');
		swap->ra--;
	}
	while (swap->rb > 0)
	{
		ft_printf("rb\n");
		rotate_operations(push, 'b');
		swap->rb--;
	}
	while (swap->rr > 0)
	{
		ft_printf("rr\n");
		rotate_operations(push, 'r');
		swap->rr--;
	}
}

void	ft_do_reverse_rotate(t_push *push, t_swap *swap)
{
	while (swap->rra > 0)
	{
		ft_printf("rra\n");
		reverse_rotate_operations(push, 'a');
		swap->rra--;
	}
	while (swap->rrb > 0)
	{
		ft_printf("rrb\n");
		reverse_rotate_operations(push, 'b');
		swap->rrb--;
	}
	while (swap->rrr > 0)
	{
		ft_printf("rrr\n");
		reverse_rotate_operations(push, 'r');
		swap->rrr--;
	}
}

void	ft_sort_stack(t_push *push, t_swap *swap)
{
	ft_counter(push, swap, push->index);
	if (swap->ra || swap->rb || swap->rr)
		ft_do_rotate(push, swap);
	if (swap->rra || swap->rrb || swap->rrr)
		ft_do_reverse_rotate(push, swap);
	ft_printf("pa\n");
	push_operations(push, 'a');
}

void	ft_stack_balance(t_push *push)
{
	int	i;

	i = 0;
	while (push->stack_a[i] != push->min)
		i++;
	if (i < push->size_a / 2 + 1)
	{
		while (i > 0)
		{
			ft_printf("ra\n");
			rotate_operations(push, 'a');
			i--;
		}
	}
	else
	{
		i = push->size_a - i;
		while (i > 0)
		{
			ft_printf("rra\n");
			reverse_rotate_operations(push, 'a');
			i--;
		}
	}
}
