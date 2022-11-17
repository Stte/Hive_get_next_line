/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 00:04:38 by tspoof            #+#    #+#             */
/*   Updated: 2022/11/17 16:30:16 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
# endif

typedef struct s_list
{
	int				fd;
	char			*content;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);

int		ft_strlen(char *s);
void	*ft_strchr(const void *s, int c, size_t n);
void	*ft_realloc(void *ptr, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
