/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:36:35 by tspoof            #+#    #+#             */
/*   Updated: 2022/11/21 13:35:19 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static size_t	gnl_newline_idx(char **buffer, int fd)
{
	size_t	i;
	char	*new_line;
	size_t	size;

	new_line = NULL;
	while (!new_line)
	{
		new_line = ft_strchr(*buffer, '\n', ft_strlen(*buffer));
		if (new_line)
		{
			i = (size_t)(new_line + 1 - *buffer);
			return (i);
		}
		*buffer = ft_malloc_increase(*buffer, ft_strlen(*buffer) + BUFFER_SIZE + 1);
		size = read(fd, *buffer + ft_strlen(*buffer), BUFFER_SIZE);
		if (!size)
		{
			if (ft_strlen(*buffer) > 0)
				return (0);
			break ;
		}
	}
	return (-1);
}

static char	*gnl_get_line(int fd, char **buffer)
{
	size_t	i;
	char	*line;
	char	*tmp;

	i = gnl_newline_idx(&buffer[fd], fd);
	if (i == (size_t)-1)
		return (NULL);
	if (i == 0)
		return (buffer[fd]);
	line = ft_substr(buffer[fd], 0, i);
	tmp = ft_substr(buffer[fd], i, ft_strlen(buffer[fd]));
	if (!tmp || !line)
		return (NULL);
	free(buffer[fd]);
	buffer[fd] = tmp;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	**buffer = NULL;
	char 		*line;

	if (fd == -1)
		return (NULL);
	if (!buffer)
		buffer = (char **)malloc(sizeof(char *) * (fd + 1));
	if (!buffer)
		return (NULL);
	if (!buffer[fd])
	{
		buffer[fd] = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer[fd])
		{
			while (fd >= 0)
			{
				free(buffer[fd]);
				fd--;
			}
			free(buffer);
			return (NULL);
		}
	}
	line = gnl_get_line(fd, buffer);
	return (line);
}
