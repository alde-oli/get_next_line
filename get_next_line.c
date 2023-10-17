/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:55:49 by alde-oli          #+#    #+#             */
/*   Updated: 2023/10/17 17:26:32 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_file	f;
	char			*line;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	f.buf = ft_read_line(f.buf, fd);
	line = ft_crop_buf(f.buf);
	f.buf = ft_get_cropped(f.buf);
	return (line);
}

char	*ft_read_line(char *buf, int fd)
{
	char	*to_add;
	int		nb_read;

	if (!buf)
		buf = ft_calloc(1);
	to_add = ft_calloc(BUFFER_SIZE + 1);
	if (!buf || !to_add)
		return (NULL);
	nb_read = read(fd, to_add, O_RDONLY);
	to_add[nb_read] = '\0';
	while (buf && nb_read > 0)
	{
		buf = ft_strjoin(buf, to_add);
		nb_read = read(fd, to_add, O_RDONLY);
		to_add[nb_read] = '\0';
	}
	free(to_add);
	return (buf);
}

char	*ft_crop_buf(char *buf)
{
	int		nl;

	nl = ft_find(buf, 0);
	if (nl == -1)
		return (ft_strndup(buf, ft_find(buf, 1)));
	return (ft_strndup(buf, ft_find(buf, 0)));
}

char	*ft_get_cropped(char *buf)
{
	char	*new_buf;
	int		nl;

	nl = ft_find(buf, 0);
	if (nl == -1)
	{
		free(buf);
		return (NULL);
	}
	new_buf = ft_strndup(buf + nl, ft_find(buf, 1) - ft_find(buf, 0));
	free(buf);
	return (new_buf);
}
