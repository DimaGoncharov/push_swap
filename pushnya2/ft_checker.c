/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 20:07:29 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/06/24 20:08:00 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	doop(t_push *push, char *oper)
{
	if (ft_strcmp(oper, "ra") == 0)
		rotate_operations(push, 'a');
	else if (ft_strcmp(oper, "rb") == 0)
		rotate_operations(push, 'b');
	else if (ft_strcmp(oper, "rr") == 0)
		rotate_operations(push, 'r');
	else if (ft_strcmp(oper, "rra") == 0)
		reverse_rotate_operations(push, 'a');
	else if (ft_strcmp(oper, "rrb") == 0)
		reverse_rotate_operations(push, 'b');
	else if (ft_strcmp(oper, "rrr") == 0)
		reverse_rotate_operations(push, 'r');
	else if (ft_strcmp(oper, "pa") == 0)
		push_operations(push, 'a');
	else if (ft_strcmp(oper, "pb") == 0)
		push_operations(push, 'b');
	else if (ft_strcmp(oper, "sa") == 0)
		swap_operations(push, 'a');
	else if (ft_strcmp(oper, "sb") == 0)
		swap_operations(push, 'b');
	else
		ft_out();
}

void	ft_valid_buf(char **buff)
{
	int i;

	i = 0;
	while (buff[i] != NULL)
	{
		if ((ft_strcmp(buff[i], "ra") == 0) || (ft_strcmp(buff[i], "rb") == 0)
		|| (ft_strcmp(buff[i], "rr") == 0) || (ft_strcmp(buff[i], "rra") == 0)
		|| (ft_strcmp(buff[i], "rrb") == 0) || (ft_strcmp(buff[i], "rrr") == 0)
		|| (ft_strcmp(buff[i], "pa") == 0) || (ft_strcmp(buff[i], "pb") == 0)
		|| (ft_strcmp(buff[i], "sa") == 0) || (ft_strcmp(buff[i], "sb") == 0))
			i++;
		else
			ft_out();
	}
	return ;
}

char	**ft_strfree(char ***arr)
{
	int i;

	i = 0;
	while ((*arr)[i])
		i++;
	while (i >= 0)
	{
		free((*arr)[i]);
		(*arr)[i] = NULL;
		i--;
	}
	free(*arr);
	*arr = NULL;
	return (NULL);
}

/*void	read_input(t_push *push)
{
	char	buff[BUFF_SIZE + 1];
	char	*del;
	int		ret;
	char	*temp;
	char	**oper;

	push->i = 0;
	temp = ft_strnew(0);
	while ((ret = read(0, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		del = temp;
		temp = ft_strjoin(temp, buff);
		free(del);
		push->i++;
		oper = ft_strsplit(temp, '\n');
		ft_valid_buf(oper);
		ft_strfree(&oper);
	}
	if (push->i == 0)
	{
		free(temp);
		return ;
	}
	push->i = -1;
	oper = ft_strsplit(temp, '\n');
	while (oper[++push->i] != NULL)
		doop(push, oper, push->i);
	ft_strfree(&oper);
	free(temp);
}*/

void		read_input(t_push *push)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		doop(push, line);
		free(line);
	}
}
