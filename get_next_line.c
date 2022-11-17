/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 00:04:35 by tspoof            #+#    #+#             */
/*   Updated: 2022/11/17 18:41:18 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	gnl_find_linebreak(char **buffer, int fd)
{
	// char	*tmp;
	// char	*line;
	size_t	i;
	char	*new_line;
	size_t	size;

	new_line = NULL;
	while (!new_line)
	{
		new_line = ft_strchr(*buffer, '\n', size);
		if (new_line)
		{
			i = (size_t)(new_line + 1 - *buffer);
			return (i);
		}
		*buffer = ft_realloc(*buffer, ft_strlen(*buffer) + BUFFER_SIZE + 1);
		size = read(fd, *buffer + ft_strlen(*buffer), BUFFER_SIZE);
		if (!size)
			break ; // return the rest?
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	// char		*new_line;
	char		*tmp;
	// size_t		size;
	size_t		i;
	char 		*line;

	if (fd == -1)
		return (NULL);
	if (!buffer)
	{
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		buffer[0] = '\0';
	}
	if (!buffer)
		return (NULL);
	i = gnl_find_linebreak(&buffer, fd);
	if(i == (size_t)-1)
		; // Do something
	line = ft_substr(buffer, 0, i);
	tmp = ft_substr(buffer, i, ft_strlen(buffer));
	if (!tmp || !line)
		return (NULL);
	free(buffer);
	buffer = tmp;
	return (line);
}


// ft_strlen(buffer) + size;
