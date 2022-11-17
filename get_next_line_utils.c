/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 00:04:31 by tspoof            #+#    #+#             */
/*   Updated: 2022/11/17 18:43:09 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
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
	size_t	i;

	n = ft_strlen((char *)src);
	if (dstsize > 0)
	{
		if (n < dstsize)
		{
			i = 0;
			while (i < n + 1)
			{
				((char *)dst)[i] = ((char *)src)[i];
				i++;
			}
		}
		else
		{
			i = 0;
			while (i < dstsize - 1)
			{
				((char *)dst)[i] = ((char *)src)[i];
				i++;
			}
			dst[dstsize - 1] = '\0';
		}
	}
	return (n);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	sub_len;
	char	*ptr;

	if (!s)
		return (NULL);
	s_len = ft_strlen((char *)s);
	if (start < s_len)
	{
		if (s_len < len)
			sub_len = s_len;
		else
			sub_len = len;
	}
	else
		sub_len = 0;
	ptr = (char *)malloc(sizeof(char) * (sub_len + 1));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s + start, sub_len + 1);
	return (ptr);
}

void	*ft_realloc(void *ptr, size_t size)
{
	char	*dst;

	if (!ptr || size == 0)
	{
		return (NULL);
	}
	dst = (char *)malloc(sizeof(char) * size);
	if (!dst)
		return (NULL);
	dst[size - 1] = '\0';
	ft_strlcpy(dst, (char *)ptr, size);
	free(ptr);
	ptr = dst;
	return (ptr);
}
