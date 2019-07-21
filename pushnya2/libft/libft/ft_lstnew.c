/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 12:11:06 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/05/05 12:11:09 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newl;

	if (!(newl = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		newl->content = NULL;
		newl->content_size = 0;
	}
	else
	{
		if (!(newl->content = ft_memalloc(content_size)))
			return (NULL);
		newl->content = ft_memmove(newl->content, content, content_size);
		newl->content_size = content_size;
	}
	newl->next = NULL;
	return (newl);
}
