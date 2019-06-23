#include "push_swap.h"

int		ft_max(t_push *push)
{
	int i;
	int max;

	i = 1;
	max = push->stack_a[0];
	while (i < push->size_a)
	{
		if (push->stack_a[i] > max)
			max = push->stack_a[i];
		i++;
	}
	return (max);
}

int		ft_min(t_push *push)
{
	int i;
	int min;

	i = 1;
	min = push->stack_a[0];
	while (i < push->size_a)
	{
		if (push->stack_a[i] < min)
			min = push->stack_a[i];
		i++;
	}
	return (min);
}

int		checker(t_push *push)
{
	int		i;
	int		pre;

	i = 1;
	if (push->stack_a[0] != push->min)
		return (0);
	pre = push->stack_a[0];
	while (i < push->size_a)
	{
		if (push->stack_a[i] < pre)
			return (0);
		pre = push->stack_a[i];
		i++;
	}
	if (push->stack_a[push->size_a - 1] != push->max)
		return (0);
	return (1);
}