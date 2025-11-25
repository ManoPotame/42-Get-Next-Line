/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrenn <mcrenn@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 09:15:54 by mcrenn            #+#    #+#             */
/*   Updated: 2025/11/25 14:29:01 by mcrenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*alloc;
	size_t	i;

	if (nmemb == 0 || size == 0)
	{
		alloc = malloc(0);
		if (!alloc)
			return (0);
		return (alloc);
	}
	if (nmemb > (size_t)-1 / size)
		return (0);
	alloc = malloc(nmemb * size);
	if (!alloc)
		return (0);
	i = 0;
	while (i < (nmemb * size))
	{
		alloc[i] = 0;
		i++;
	}
	return (alloc);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	index;

	if (!s)
		return (NULL);
	index = 0;
	while (s[index])
	{
		if (s[index] == (char)c)
			return ((char *)&s[index]);
		index ++;
	}
	if ((char)c == '\0')
	{
		return ((char *)&s[index]);
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (s2 == NULL)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	free(s1);
	return (str);
}
