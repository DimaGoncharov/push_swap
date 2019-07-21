/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:29:27 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/02/03 17:10:23 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check(char **str, char **line)
{
	char		*ptr;
	size_t		len;
	char		*temp;

	if (!(*str))
		*str = ft_strnew(0);
	ptr = *str;
	if (ft_strchr(*str, '\n'))
	{
		*line = ft_strsub(ptr, 0, (ft_strchr(ptr, '\n') - ptr));
		len = ft_strlen(ft_strchr(ptr, '\n')) - 1;
		temp = ft_strsub(ptr, ((ft_strchr(ptr, '\n') + 1) - ptr), len);
		free(*str);
		*str = temp;
		return (1);
	}
	return (0);
}

static void		clean(char **mas, char **temp, char *tmp)
{
	*temp = ft_strjoin(*mas, tmp);
	free(*mas);
	*mas = *temp;
}

int				get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	size_t		ret;
	static char	*line2[10240];
	char		*temp;

	if (BUFF_SIZE < 1 || fd < 0 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	if (ft_check(&line2[fd], line) == 1)
		return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		clean(&line2[fd], &temp, buf);
		if (ft_check(&line2[fd], line) == 1)
			return (1);
	}
	*line = ft_strnew(ft_strlen(line2[fd]));
	ft_memcpy(*line, line2[fd], ft_strlen(line2[fd]));
	if (*line2[fd] != '\0')
	{
		*line2[fd] = '\0';
		return (1);
	}
	free(*line);
	return (0);
}
