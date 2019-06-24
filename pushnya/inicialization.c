/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inicialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 19:39:06 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/06/24 20:07:01 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_inicialization_push(t_push *push)
{
	push->vis = 0;
	push->i = 0;
	push->stack_a = NULL;
	push->stack_b = NULL;
	push->size_a = 0;
	push->size_b = 0;
	push->res = 0;
	push->index = -1;
	push->fl = 0;
}

void	ft_initialization_swap(t_swap *swap)
{
	swap->pa = 0;
	swap->pb = 0;
	swap->ra = 0;
	swap->rb = 0;
	swap->rr = 0;
	swap->rra = 0;
	swap->rrb = 0;
	swap->rrr = 0;
}

void	ft_record(t_push *push, char *argv)
{
	while (*argv != '\0')
	{
		if (argv[0] == '-' && argv[1] == 'v')
			argv++;
		else	if ((*argv >= '0' && *argv <= '9') ||
				(*argv == '-' || *argv == '+'))
		{
			push->stack_a[push->i] = ft_atoi(argv);
			if (ft_check_overflow(push, argv, push->stack_a[push->i]) == 1)
				ft_out();
			while (*argv != ' ' && *argv != '\0')
				argv++;
			argv--;
			push->i++;
		}
		argv++;
	}
}

int		ft_check_overflow(t_push *push, char *argv, int num)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (push->vis && argv[0] == '-' && argv[1] == 'v')
		return (0);
	str = ft_itoa(num);
	if (num != 0)
	{
		j = ft_skip_null_znak(argv);
		i = ft_skip_null_znak(str);
	}
	while (str[i] != '\0')
	{
		if (argv[j] != str[i])
			return (1);
		i++;
		j++;
	}
	return (0);
}

void	printstack(t_push *push)
{
	int	i;
	int	t;

	t = (push->size_a > push->size_b ? push->size_a : push->size_b);
	i = -1;
	if (push->vis)
	{
		ft_printf("----------------------------\n");
		ft_printf("|%-11c ||" "%11c |\n", 'a', 'b');
		ft_printf("----------------------------");
		ft_printf("\n");
		while (++i < t)
		{
			if (i < push->size_a)
				ft_printf("|%11ld |", push->stack_a[i]);
			else
				ft_printf("|%11s |", " ");
			if (i < push->size_b)
				ft_printf("|%11ld |\n", push->stack_b[i]);
			else
				ft_printf("|%11s |\n", " ");
		}
		ft_printf("----------------------------\n\n");
	}
}
