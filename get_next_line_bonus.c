/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:55:49 by alde-oli          #+#    #+#             */
/*   Updated: 2023/10/17 22:46:29 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_file	files[MAX_FILES];
	t_file			*f;
	char			*line;

	f = ft_find_file(files, fd);
	if (BUFFER_SIZE < 1 || fd < 0 || !f)
		return (NULL);
	f->buf = ft_read_line(f->buf, fd);
	if (!f->buf)
		return (NULL);
	line = ft_crop_buf(f->buf);
	f->buf = ft_get_cropped(f->buf);
	return (line);
}

t_file	*ft_find_file(t_file *files, int fd)
{
	int		i;

	i = 0;
	while (i < MAX_FILES && files[i].is_init)
	{
		if (files[i].fd == fd)
			return (&files[i]);
		i++;
	}
	if (i < MAX_FILES)
	{
		files[i].fd = fd;
		files[i].is_init = 1;
		return (&files[i]);
	}
	return (NULL);
}

char	*ft_read_line(char *buf, int fd)
{
	char	*to_add;
	int		nb_read;

	nb_read = 1;
	if (!buf)
		buf = ft_calloc(1);
	to_add = ft_calloc(BUFFER_SIZE + 1);
	if (!buf || !to_add)
		return (NULL);
	while (nb_read > 0)
	{
		nb_read = read(fd, to_add, BUFFER_SIZE);
		if (nb_read < 0)
		{
			free(buf);
			free(to_add);
			return (NULL);
		}
		to_add[nb_read] = '\0';
		buf = ft_strjoin(buf, to_add);
		if (ft_find(buf, 0) > -1)
			break ;
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
