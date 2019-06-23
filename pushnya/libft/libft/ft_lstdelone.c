/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 12:15:17 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/05/05 12:15:21 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del) (void *, size_t))
{
	size_t	size;
	void	*ptr;

	size = (*alst)->content_size;
	ptr = (*alst)->content;
	del(ptr, size);
	free(*alst);
	*alst = NULL;
}
