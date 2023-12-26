/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:40:23 by relamine          #+#    #+#             */
/*   Updated: 2023/12/26 11:26:40 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	s2 = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!s2)
		return (NULL);
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
	char	*str;
	size_t	i;
	size_t	j;
	size_t	lens1;
	size_t	lens2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	i = 0;
	j = 0;
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	str = malloc(lens1 + lens2 + 1);
	if (!str)
		return (NULL);
	while (i < lens1)
	{
		str[i] = s1[i];
		i++;
	}
	while (j < lens2)
		str[i++] = s2[j++];
	str[i] = '\0';
	free((char *)s1);
	return ((char *)str);
}
int	ft_strchr(char *s, int c)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = (char *)s;
	while (*s != '\0')
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
	size_t 	j;

	if (!s)
		return (NULL);
	strlen_of_start = ft_strlen(&s[start]);
	if (len > strlen_of_start)
		size = strlen_of_start + 1;
	else
		size = len + 1;
	res = malloc(size);
	if (!res)
		return (NULL);
	j = 0;
	src = &s[start];
	if (size > 0)
	{
		while (src[j] != '\0' && j < size -1)
		{
			res[j] = src[j];
			j++;
		}
		res[j] = '\0';
	}
	return (res);
}
