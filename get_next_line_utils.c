/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 00:04:31 by tspoof            #+#    #+#             */
/*   Updated: 2022/11/16 14:41:34 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_strlen(char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_strchr(const void *s, int c, size_t n)
{
	size_t	slen;
	size_t	i;

	slen = ft_strlen((char *)s) + 1;
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

static size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	n;

	n = ft_strlen(src);
	if (dstsize > 0)
	{
		if (n < dstsize)
			ft_memcpy(dst, src, n + 1);
		else
		{
			ft_memcpy(dst, src, dstsize - 1);
			dst[dstsize - 1] = '\0';
		}
	}
	return (n);
}

void	*ft_realloc(void *ptr, size_t size)
{
	char	*dst;

	dst = (char *)malloc(sizeof(char) * size);
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, (char *)ptr, size);
	free(ptr);
	ptr = dst;
}
