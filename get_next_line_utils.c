/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 00:04:31 by tspoof            #+#    #+#             */
/*   Updated: 2022/11/10 14:43:32 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_strlen(char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*gnl_memchr(const void *s, int c, size_t n)
{
	size_t	slen;
	size_t	i;

	slen = gnl_strlen((char *)s) + 1;
	i = 0;
	while (i < slen && i < n)
	{
		if (*(unsigned char *)(s + i) == (unsigned char)c)
		{
			return ((char *)(s + i));
		}
		i++;
	}
	return (NULL);
}
