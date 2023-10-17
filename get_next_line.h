/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:56:29 by alde-oli          #+#    #+#             */
/*   Updated: 2023/10/17 17:23:39 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_file
{
	int		fd;
	char	*buf;
}	t_file;

//gnl functions
char	*get_next_line(int fd);
char	*ft_read_line(char *buf, int fd);
char	*ft_crop_buf(char *buf);
char	*ft_get_cropped(char *buf);
//utils
int		ft_find(char *s, int mod);
char	*ft_calloc(int size);
char	*ft_strndup(char *src, int max);
char	*ft_strjoin(char *buf, char *to_add);

#endif