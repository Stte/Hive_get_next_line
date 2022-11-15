/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 00:04:35 by tspoof            #+#    #+#             */
/*   Updated: 2022/11/15 15:32:17 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*get_next_line(int fd)
// {
// 	static char	*buffer = NULL;
// 	size_t		size;


// 	size = read(fd, buffer, BUFFER_SIZE);



// 	return (NULL);
// }

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*prev;
	size_t		size;
	static int	i;

	size = 0;
	if (!fd)
		return (NULL);
	if (!buffer)
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (*buffer == '\0')
		size = read(fd, buffer, BUFFER_SIZE);
		// have to check if \n not found

	prev = buffer;
	buffer = gnl_strchr(buffer, '\n', BUFFER_SIZE) + 1;
	if (buffer)
		i = (int)(buffer - prev);
		// return prev till buffer
	if (size && prev)
		size = 0;

	return (NULL);
}


// read file if nothing in buffer
// return string till newline

//if I move the buffer pointer I can't free the memory
