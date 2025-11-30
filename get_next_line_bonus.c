/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrenn <mcrenn@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 09:16:01 by mcrenn            #+#    #+#             */
/*   Updated: 2025/11/30 13:25:21 by mcrenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*storer(char *buffer, int fd)
{
	char	*stock;
	int		reader;

	reader = 1;
	stock = malloc((size_t)BUFFER_SIZE + 1);
	if (!stock)
		return (NULL);
	while (!ft_strchr(buffer, '\n') && reader > 0)
	{
		reader = read(fd, stock, BUFFER_SIZE);
		if (reader < 0)
		{
			free(stock);
			free(buffer);
			return (NULL);
		}
		if (reader == 0)
			break ;
		stock[reader] = '\0';
		buffer = ft_strjoin(buffer, stock);
	}
	free(stock);
	return (buffer);
}

static char	*line_extractor(char *buffer)
{
	char	*current_line;
	int		i;

	i = 0;
	if (!buffer || buffer[i] == '\0')
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	current_line = ft_calloc(sizeof(char), i + 1);
	if (!current_line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		current_line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		current_line[i++] = '\n';
	current_line[i] = '\0';
	return (current_line);
}

static char	*buffer_updater(char *buffer)
{
	char	*updated_buffer;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	updated_buffer = ft_calloc(sizeof(char), ft_strlen(buffer) - i + 1);
	if (!updated_buffer)
	{
		free(buffer);
		return (NULL);
	}
	j = 0;
	i++;
	while (buffer[i])
		updated_buffer[j++] = buffer[i++];
	free(buffer);
	return (updated_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*current_line;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer[fd])
		buffer[fd] = ft_calloc(sizeof(char), 1);
	if (!buffer[fd])
		return (NULL);
	buffer[fd] = storer(buffer[fd], fd);
	if (!buffer[fd])
		return (NULL);
	current_line = line_extractor(buffer[fd]);
	if (!current_line)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	buffer[fd] = buffer_updater(buffer[fd]);
	return (current_line);
}
