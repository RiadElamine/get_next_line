/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:40:23 by relamine          #+#    #+#             */
/*   Updated: 2023/12/25 08:07:29 by relamine         ###   ########.fr       */
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
static size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	j;

	src_len = ft_strlen(src);
	j = 0;
	if (dstsize > 0)
	{
		while (src[j] != '\0' && j < dstsize -1)
		{
			dst[j] = src[j];
			j++;
		}
		dst[j] = '\0';
	}
	return (src_len);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	if (!s2)
		return (ft_strdup(s1));
	if (!s1)
		return (ft_strdup(s2));
	i = 0;
	j = 0;
	str = malloc(ft_strlen(s2) + ft_strlen(s1) + 1);
	if (!str)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		str[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
		str[i++] = s2[j++];
	str[i] = '\0';
	return ((char *)str);
}
char	*ft_strchr(const char *s, int c)
{
	size_t	la;

	la = 0;
	while (la < ft_strlen(s))
	{
		if ((char)c == s[la])
			return ((char *)(s + la));
		la++;
	}
	return (NULL);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	int		size ;
	size_t	strlen_of_start;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	strlen_of_start = ft_strlen(&s[start]);
	if (len > strlen_of_start)
		size = strlen_of_start + 1;
	else
		size = len + 1;
	res = malloc(size * sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, &s[start], size);
	return (res);
}
