/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:27:57 by relamine          #+#    #+#             */
/*   Updated: 2024/01/01 23:25:09 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	s2 = malloc(ft_strlen(s1) + 1);
	if (!s2)
		return (free((char *)s1), NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
    char	*rs;
    int     i;
    int     j;
    size_t  lens1;
    size_t  lens2;  

    if(!s1)
        return (ft_strdup(s2));
    lens1 = ft_strlen(s1);
    lens2 = ft_strlen(s2);
    rs = malloc(lens1 + lens2 + 1);
    if (!rs)
        return (free((char *)s1), free((char *)s2), NULL);
    rs[lens1 + lens2] = '\0';
    i = 0;
    while (s1[i])
    {
        rs[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2[j])
        rs[i++] = s2[j++];
    return (free((char *)s1), rs);
}
int	ft_strchr(char *s, int c)
{
	char	*tmp;

	tmp = (char *)s;
	while (*s)
	{
		if ((char)c == *s)
			return ((int)(s - tmp));
		s++;
	}
	return (-1);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	char const		*src;
	size_t		size ;
	size_t	strlen_of_start;
	size_t 	i;

	src = &s[start];
	strlen_of_start = ft_strlen(src);
	if (len > strlen_of_start)
		size = strlen_of_start + 1;
	else
		size = len + 1;
	res = malloc(size);
	if (!res)
		return (NULL);
	i = 0;
	while (i < size -1)
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

