/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:27:20 by relamine          #+#    #+#             */
/*   Updated: 2024/01/02 00:25:10 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_line_get(char **buffer)
{
	char	*line;
	int		findnl;
	char	*tmp;

	findnl = ft_strchr(*buffer, '\n');
	if (findnl == -1)
	{
		line = ft_strdup(*buffer);
		if (line)
			free(*buffer);
		return (*buffer = NULL, line);
	}
	line = ft_substr(*buffer, 0, findnl + 1);
	if (!line)
		return (free(*buffer), *buffer = NULL, NULL);
	tmp = *buffer;
	if (tmp[findnl + 1] == '\0')
		return (free(tmp), *buffer = NULL, line);
	*buffer = ft_substr(tmp, findnl + 1, INT_MAX);
	return (free(tmp), line);
}

static char	*ft_reading(char *buffer, int fd)
{
	ssize_t	byte;
	char	*arr;

	arr = malloc((size_t)BUFFER_SIZE + 1);
	if (!arr)
		return (free(buffer), NULL);
	byte = read(fd, arr, BUFFER_SIZE);
	while (byte > 0)
	{
		arr[byte] = '\0';
		buffer = ft_strjoin(buffer, arr);
		if (!buffer)
			return (NULL);
		if (ft_strchr(arr, '\n') != -1)
			break ;
		byte = read(fd, arr, BUFFER_SIZE);
	}
	if (byte == -1)
		return (free(arr), free(buffer), NULL);
	return (free(arr), buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];

	if ((fd >= 0 && fd < OPEN_MAX) && (BUFFER_SIZE > 0 && BUFFER_SIZE <= INT_MAX))
	{
		buffer[fd] = ft_reading(buffer[fd], fd);
		if (buffer[fd])
			return (ft_line_get(&buffer[fd]));
	}
	return (NULL);
}

// void f()
// {
//   system("leaks a.out");
// }
// int main()
// {
//     int fd = open("file2.txt", O_RDONLY);
//     if (!fd)
//         return (-1);
//     char *s = get_next_line(fd);
//     printf("%s", s);
//     free(s);
// s = get_next_line(fd);
//     printf("%s", s);
//     free(s);
//     // int fd1 = open("file3.txt", O_RDONLY);
//     // if (!fd1)
//     //     return (-1);
//     // char *s1 = get_next_line(fd1);
//     // printf("%s", s1);
//     // free(s1);
//     // // int fd2 = open("file2.txt", O_RDONLY);
//     // // if (!fd2)
//     // //     return (-1);
//     // s = get_next_line(fd);
//     // printf("%s", s);
//     // free(s);

//     atexit(f);
// }
