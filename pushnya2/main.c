/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 19:35:49 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/06/24 20:03:38 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_do_count(t_push *push)
{
	while (push->size_b)
	{
		push->fl = 0;
		ft_count_operation(push);
	}
}

int		main(int ac, char **av)
{
	int		num;
	t_push	*push;

	num = 0;
	if (!(push = (t_push*)malloc(sizeof(t_push))))
		ft_out();
	ft_inicialization_push(push);
	while (++num < ac)
		ft_valid(av[num], push);
	ft_memory(push);
	num = 0;
	while (++num < ac)
		ft_record(push, av[num]);
	ft_check_repeat(push);
	push->max = ft_max(push);
	push->min = ft_min(push);
	if (ft_check_cyclic_sort(push) == 1 || checker(push) == 1)
	{
		ft_stack_balance(push);
		exit(0);
	}
	ft_separate_stack(push);
	ft_do_count(push);
	ft_stack_balance(push);
	exit(0);
}
