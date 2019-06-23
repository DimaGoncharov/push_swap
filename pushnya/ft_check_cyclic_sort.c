#include "push_swap.h"

int		ft_check_cyclic_sort(t_push *push)
{
	int i;

	i = 0;
	while (push->stack_a[i] != push->min)
		i++;
	while (i + 1 < push->size_a)
	{
		if (push->stack_a[i] < push->stack_a[i + 1])
			i++;
		else
			return (0);
	}
	if (push->stack_a[0] > push->stack_a[i])
		i = 0;
	else
		return (0);
	while (push->stack_a[i + 1] != push->min)
	{
		if (push->stack_a[i] < push->stack_a[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

void	ft_do_separate(t_push *push)
{
	if (push->i < push->size_a - push->i)
	{
		while (push->i > 0)
		{
			ft_printf("ra\n");
			rotate_operations(push, 'a');
			push->i--;
		}
	}
	else
	{
		while (push->size_a - push->i > 0)
		{
			ft_printf("rra\n");
			reverse_rotate_operations(push, 'a');
			push->i++;
		}
	}
	ft_printf("pb\n");
	push_operations(push, 'b');
	push->i = 0;
}

void	ft_separate_stack(t_push *push)
{
	push->i = 0;
	while (push->size_a > 3)
	{
		if ((push->stack_a[push->i] != push->min)
		&& (push->stack_a[push->i] != push->max))
			ft_do_separate(push);
		else
			push->i++;
	}
	if (push->size_a == 3 && ft_check_sort_elements(push) == 0)
		ft_sort_three_item(push);
	push->i = 0;
}

int		ft_check_sort_elements(t_push *push)
{
	if ((push->stack_a[0] < push->stack_a[1]
	&& push->stack_a[1] < push->stack_a[2])
	|| (push->stack_a[0] == push->max && push->stack_a[1] < push->stack_a[2])
	|| (push->stack_a[0] < push->stack_a[1] && push->stack_a[2] == push->min))
		return (1);
	else
		return (0);
}
