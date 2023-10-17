/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:55:49 by alde-oli          #+#    #+#             */
/*   Updated: 2023/10/17 22:45:56 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

int	main(void)
{
	int		fd1;
	int		fd2;
	char	*line;

	fd1 = open("text.txt", O_RDONLY);
	fd2 = open("text2.txt", O_RDONLY);

	line = get_next_line(fd1);
	printf("%s", line);
	if (line)
		free(line);
	
	line = get_next_line(fd2);
	printf("%s", line);
	if (line)
		free(line);
	
	line = get_next_line(fd2);
	printf("%s", line);
	if (line)
		free(line);
	
	line = get_next_line(fd1);
	printf("%s", line);
	if (line)
		free(line);
	
	line = get_next_line(fd2);
	printf("%s", line);
	if (line)
		free(line);
	
	line = get_next_line(fd2);
	printf("%s", line);
	if (line)
		free(line);
}
