/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 00:04:35 by tspoof            #+#    #+#             */
/*   Updated: 2022/11/24 16:59:48 by tspoof           ###   ########.fr       */
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

static int	gnl_read(int fd, char **content)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*new_line;
	char	*tmp;
	size_t	size;

	new_line = NULL;
	while (!new_line)
	{
		new_line = ft_strchr(*content, '\n');
		if (new_line)
			return (2);
		gnl_zerobuffer(buffer);
		size = read(fd, buffer, BUFFER_SIZE);
		if (!size)
			break ;
		tmp = ft_strjoin(*content, buffer);
		if (!tmp)
			return (0);
		free(*content);
		*content = tmp;
	}
	return (1);
}

static char	*gnl_get_line(char **content)
{
	char	*line;
	char	*tmp;
	size_t	i;

	tmp = ft_strchr(*content, '\n');
	i = (size_t)(tmp - *content) + 1;
	line = ft_substr(*content, 0, i);
	tmp = ft_substr(*content, i, ft_strlen(*content));
	if (!tmp || !line)
		return (NULL);
	free(*content);
	*content = tmp;
	return (line);
}

static char	*gnl_line(int read_return, char **content)
{
	char	*line;

	if (read_return == 1)
	{
		line = ft_substr(*content, 0, ft_strlen(*content));
		free(*content);
		return (line);
	}
	line = gnl_get_line(content);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*fd_list[1024] = {0};
	char		*line;
	int			read_return;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	if (!fd_list[fd])
	{
		fd_list[fd] = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		// PROTEK!
		fd_list[fd][0] = '\0';
	}
	if (!fd_list[fd])
		return (NULL);
	read_return = gnl_read(fd, &fd_list[fd]);
	if (!read_return)
	{
		free(fd_list[fd]);
		return (NULL);
	}
	line = gnl_line(read_return, &fd_list[fd]);
	return (line);
}
