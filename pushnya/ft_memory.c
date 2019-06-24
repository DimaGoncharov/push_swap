/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 19:42:12 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/06/24 20:13:13 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_out(void)
{
	ft_printf("Error\n");
	exit(0);
}

void	ft_memory(t_push *push)
{
	if (!(push->stack_a = (long *)malloc(push->size_a * sizeof(long))))
		ft_out();
	if (!(push->stack_b = (long *)malloc(push->size_a * sizeof(long))))
		ft_out();
}

void	ft_count_digits(char *av, t_push *push)
{
	int	i;
	int	fl;

	i = 0;
	fl = 0;
	while (av[i] != '\0')
	{
		if (av[i] == ' ' || (push->vis && av[i] == '-') ||
				(push->vis && av[i] == 'v'))
		{
			i++;
			fl = 0;
		}
		else	if (((av[i] >= '0' && av[i] <= '9') ||
					(av[i] == '-' || av[i] == '+')) && fl == 0)
		{
			push->size_a++;
			fl = 1;
			i++;
		}
		else	if ((av[i] >= '0' && av[i] <= '9') && fl == 1)
			i++;
	}
}

void	ft_valid(char *av, t_push *push)
{
	int	i;

	i = 0;
	while (av[i] != '\0')
	{
		if (((av[i] == '-' || av[i] == '+') && (av[i + 1] >= '0' &&
						av[i + 1] <= '9')) && (i == 0 || av[i - 1] == ' '))
			i++;
		else	if ((av[i] >= '0' && av[i] <= '9') || (av[i] == ' '))
			i++;
		else	if (av[0] == '-' && av[1] == 'v')
		{
			push->vis = 1;
			i = i + 2;
		}
		else
			ft_out();
	}
	ft_count_digits(av, push);
}
