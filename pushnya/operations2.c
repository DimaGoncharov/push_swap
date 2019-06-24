/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 19:36:53 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/06/24 19:36:55 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_do_pb(t_push *push, int *i)
{
	if (push->size_b > 0)
		while ((*i) > 0)
		{
			push->stack_b[*i] = push->stack_b[(*i) - 1];
			(*i)--;
		}
	(*i) = -1;
	ft_swap(&push->stack_a[0], &push->stack_b[0]);
	push->size_a--;
	push->size_b++;
	while (++(*i) < push->size_a)
		push->stack_a[*i] = push->stack_a[*i + 1];
}

void	ft_do_pa(t_push *push, int *i)
{
	if (push->size_a > 0)
		while ((*i) > 0)
		{
			push->stack_a[*i] = push->stack_a[(*i) - 1];
			(*i)--;
		}
	(*i) = -1;
	ft_swap(&push->stack_b[0], &push->stack_a[0]);
	push->size_b--;
	push->size_a++;
	while (++(*i) < push->size_b)
		push->stack_b[*i] = push->stack_b[*i + 1];
}

void	push_operations(t_push *push, char letter)
{
	int i;

	i = letter == 'a' ? push->size_a : push->size_b;
	if (letter == 'b' && push->size_a > 0)
		ft_do_pb(push, &i);
	else if (letter == 'a' && push->size_b > 0)
		ft_do_pa(push, &i);
	printstack(push);
}

void	rotate_operations(t_push *push, char letter)
{
	long	tmp;
	int		i;

	i = -1;
	tmp = letter == 'a' ? push->stack_a[0] : push->stack_b[0];
	if (letter == 'a' && push->size_a > 0)
	{
		while (++i < push->size_a)
			push->stack_a[i] = push->stack_a[i + 1];
		push->stack_a[push->size_a - 1] = tmp;
	}
	else if (letter == 'b' && push->size_a > 0)
	{
		while (++i < push->size_b)
			push->stack_b[i] = push->stack_b[i + 1];
		push->stack_b[push->size_b - 1] = tmp;
	}
	else if (letter == 'r')
	{
		rotate_operations(push, 'a');
		rotate_operations(push, 'b');
	}
	printstack(push);
}
