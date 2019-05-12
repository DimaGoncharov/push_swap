/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 11:53:24 by ptorchbu          #+#    #+#             */
/*   Updated: 2018/12/27 12:27:54 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_list_reverse(t_flist **begin_list)
{
	t_flist *i;
	t_flist *j;
	t_flist *k;

	i = *begin_list;
	j = 0;
	k = 0;

	if (*begin_list)
	{
	while (i)
	{
			k = j;
			j = i;
			i = i->next;
			j->next = k;
		}
	*begin_list = j;
	}
}
