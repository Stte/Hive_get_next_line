/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:36:54 by tspoof            #+#    #+#             */
/*   Updated: 2022/11/22 16:28:35 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	size_t	i;

	if (dstsize > 0)
	{
		i = 0;
		while (i < dstsize - 1 && src[i])
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen((char *)src));
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, s1_len + 1);
	ft_strlcpy(str + s1_len, s2, s2_len + 1);
	str[s1_len + s2_len] = '\0';
	return (str);
}
