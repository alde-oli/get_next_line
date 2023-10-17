/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:56:29 by alde-oli          #+#    #+#             */
/*   Updated: 2023/10/17 22:41:28 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# define MAX_FILES 100

typedef struct s_file
{
	int		fd;
	int		is_init;
	char	*buf;
}	t_file;

//gnl functions
char	*get_next_line(int fd);
t_file	*ft_find_file(t_file *files, int fd);
char	*ft_read_line(char *buf, int fd);
char	*ft_crop_buf(char *buf);
char	*ft_get_cropped(char *buf);
//utils
int		ft_find(char *s, int mod);
char	*ft_calloc(int size);
char	*ft_strndup(char *src, int max);
char	*ft_strjoin(char *buf, char *to_add);

#endif