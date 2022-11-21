/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 00:04:35 by tspoof            #+#    #+#             */
/*   Updated: 2022/11/21 19:49:06 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	gnl_zerobuffer(char *buff)
{
	size_t	i;

	i = 0;
	while (i < BUFFER_SIZE + 1)
	{
		buff[i] = '\0';
		i++;
	}
}

static size_t	gnl_newline_idx(char **buffer, int fd)
{
	size_t	i;
	char	*new_line;
	size_t	size;
	char	sub_buff[BUFFER_SIZE + 1];
	char	*tmp;

	new_line = NULL;
	while (!new_line)
	{
		new_line = ft_strchr(*buffer, '\n', ft_strlen(*buffer));
		if (new_line)
			return ((size_t)(new_line + 1 - *buffer));
		gnl_zerobuffer(sub_buff);
		size = read(fd, sub_buff, BUFFER_SIZE);
		if (!size || size < 0)
			break ;
		tmp = ft_strjoin(*buffer, sub_buff);
		if (!tmp)
		{
			*buffer = NULL;
			return (0);
		}
		free(*buffer);
		*buffer = tmp;
	}
	return (0);
}

static char	*gnl_get_line(char **buffer, int end)
{
	char	*line;
	char	*tmp;

	if (!buffer || !(*buffer[0]))
		return (NULL);
	line = ft_substr(*buffer, 0, end);
	tmp = ft_substr(*buffer, end, ft_strlen(*buffer));
	if (!tmp || !line)
	{
		free(*buffer);
		*buffer = NULL;
		return (NULL);
	}
	free(*buffer);
	*buffer = tmp;
	return (line);
}

static char	*gnl_check_buff(int i, char **buffer)
{

}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	size_t		i;
	char		*line;

	if (fd == -1 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	i = gnl_newline_idx(&buffer, fd);
	if (i == 0)
	{
		if (ft_strlen(buffer) > 0)
		{
			line = buffer;
			buffer = NULL;
			return (line);

		}
		else
		{
			free(buffer);
			buffer = NULL;
			return (NULL);
		}
	}
	line = gnl_get_line(&buffer, i);
	return (line);
}
