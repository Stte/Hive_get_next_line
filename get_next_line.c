/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 00:04:35 by tspoof            #+#    #+#             */
/*   Updated: 2022/11/22 20:31:29 by tspoof           ###   ########.fr       */
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

static char	*gnl_get_line(char **content)
{
	char	*line;
	char	*tmp;
	size_t	i;

	tmp = ft_strchr(*content, '\n', ft_strlen(*content));
	i = (size_t)(tmp - *content) + 1;
	line = ft_substr(*content, 0, i);
	tmp = ft_substr(*content, i, ft_strlen(*content));
	if (!tmp || !line)
		return (NULL);
	free(*content);
	*content = tmp;
	return (line);
}

static void	*gnl_read(int fd, char **content)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*new_line;
	char	*tmp;
	size_t	size;

	new_line = NULL;
	while (!new_line)
	{
		new_line = ft_strchr(*content, '\n', ft_strlen(*content));
		if (new_line)
			return (*content);
		gnl_zerobuffer(buffer);
		size = read(fd, buffer, BUFFER_SIZE);
		if (!size)
			break ;
		tmp = ft_strjoin(*content, buffer);
		if (!tmp)
			return (NULL);
		free(*content);
		*content = tmp;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*fd_list[1024];
	char		*line;

	if (fd == -1 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!fd_list[fd])
	{
		fd_list[fd] = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		fd_list[fd][0] = '\0';
	}
	if (!fd_list[fd])
		return (NULL);
	if (!gnl_read(fd, &fd_list[fd]))
	{
		line = NULL;
		if (fd_list[fd][0])
			line = ft_substr(fd_list[fd], 0, ft_strlen(fd_list[fd]));
		free(fd_list[fd]);
		fd_list[fd] = NULL;
		if (line)
			return (line);
		return (NULL);
	}
	line = gnl_get_line(&fd_list[fd]);
	return (line);
}
