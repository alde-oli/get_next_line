/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:32:52 by alde-oli          #+#    #+#             */
/*   Updated: 2023/11/09 10:17:27 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_find(char *s, int mod)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!mod && s[i] == '\n')
			return (i + 1);
		i++;
	}
	if (mod)
		return (i);
	return (-1);
}

char	*ft_free(char *str)
{
	free(str);
	return (NULL);
}

void	*ft_calloc(int size)
{
	void	*ptr;
	int		i;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		((char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		j;
	int		i;
	int		len;
	char	*dest;

	len = ft_find(s1, 1) + ft_find(s2, 1) + 1;
	dest = ft_calloc(len * sizeof(char));
	if (!dest)
		return (ft_free(s1));
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	ft_free(s1);
	return (dest);
}

char	*ft_strndup(char *src, int i)
{
	int		j;
	char	*dest;

	j = 0;
	dest = ft_calloc((i + 2) * sizeof(char));
	if (!dest)
		return (NULL);
	while (j <= i && src[j])
	{
		dest[j] = src[j];
		j++;
	}
	return (dest);
}
