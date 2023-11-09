/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:56:29 by alde-oli          #+#    #+#             */
/*   Updated: 2023/11/09 10:01:30 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 5000
# endif

typedef struct s_file
{
	int		fd;
	int		is_init;
	char	*buf;
}	t_file;

//gnl
char	*get_next_line(int fd);
t_file	*ft_find_file(t_file *files, int fd);
char	*ft_gen_line(char *stock, int fd);
char	*ft_crop_line(char *stock);
char	*ft_get_cropped(char *stock);
char	*ft_free(char *str);
//gnl_utils
int		ft_find_nl(char *str);
void	*ft_calloc(int size);
char	*ft_strjoin(char *stock, char *tmp);
int		ft_strlen(char *str);
char	*ft_strndup(char *stock, int i);

#endif
