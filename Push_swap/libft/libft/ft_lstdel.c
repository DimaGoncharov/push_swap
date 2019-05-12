/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 12:10:25 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/05/05 12:10:28 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*iter;

	while (*alst)
	{
		iter = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = iter;
	}
	alst = NULL;
}
