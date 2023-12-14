/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:15:45 by relamine          #+#    #+#             */
/*   Updated: 2023/12/13 22:52:17 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "get_next_line.h"

#define buffer_size 9


// void f()
// {
//   system("leaks a.out");
// }
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
char *get_next_line(int fd) {
  static int count = 0;
  int index = 1;

  count++;
  char *array = malloc(buffer_size + 1);
  ssize_t byte_reading;

  while (index <= buffer_size)
  {
    byte_reading = read(fd, &array[index - 1], 1);
    if (byte_reading == -1)
    {
      perror ("Error in reading file");
      return (NULL);
    }
    else if (byte_reading == 0)
    {
      return (NULL);
    }
    if (array[index - 1] == '\n')
    {
      index++;
      break;
    }
    index++;
  }
  char *array2 = malloc(1001);
  while (index <= 1000)
  {
    byte_reading = read(fd, &array2[index - 1], 1);
    if (byte_reading == -1)
    {
      perror ("Error in reading file");
      return (NULL);
    }
    else if (byte_reading == 0)
    {
      return (NULL);
    }
    if (array2[index - 1] == '\n')
    {
      break;
    }
    index++;
  }
  array2[index] = '\0';
  array[buffer_size] = '\0';
  char *ar=ft_strjoin(array, array2);
  // printf("%d\n",count);
  return (ar);
}
int main()
 {
  
  int fd = open("file.txt", O_RDONLY);
  if (fd == -1)
  {
    perror ("Error in opening file");
    return -1;
  }
  printf("%s",get_next_line(fd));
 



  close(fd);
  // atexit(f);
  return (0);
 }
