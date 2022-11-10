/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 00:04:35 by tspoof            #+#    #+#             */
/*   Updated: 2022/11/10 14:53:53 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*prev;
	size_t		size;

	if (!fd)
		return (NULL);
	if (!buffer)
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (*buffer == '\0')
		size = read(fd, buffer, BUFFER_SIZE);

	prev = buffer;
	// I have to take care how I free the all of the memory allocated
	buffer = gnl_memchr(buffer, '\n', BUFFER_SIZE) + 1;
	if (buffer)
		// return prev till buffer -1
	if (size && prev)
		size = 0;

	return (NULL);
}
