#include "push_swap.h"

int		main(int ac, char **av)
{
	int		count;
	t_push	*push;

	count = 0;
	if (!(push = (t_push *)malloc(sizeof(t_push))))
		ft_out();
	ft_inicialization_push(push);
	while (++count < ac)
		ft_valid(av[count], push);
	if (push->size_a > 0)
	{
		ft_memory(push);
		count = 0;
		while (++count < ac)
			ft_record(push, av[count]);
		ft_check_repeat(push);
		push->max = ft_max(push);
		push->min = ft_min(push);
		read_input(push);
		(checker(push)) == 1 ? ft_printf("OK\n") : ft_printf("KO\n");
	}
	exit(0);
}