/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 19:38:46 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/06/24 20:03:51 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_check_repeat(t_push *push)
{
	int	i;
	int j;

	i = 0;
	while (i < push->size_a)
	{
		j = 0;
		while (j < push->size_a)
		{
			if (i == j || push->stack_a[i] != push->stack_a[j])
				j++;
			else
				ft_out();
		}
		i++;
	}
	return (1);
}

int		ft_skip_null_znak(char *argv)
{
	int i;

	i = 0;
	while (argv[i] == '0' || argv[i] == '+')
		i++;
	return (i);
}
