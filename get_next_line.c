/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:15:45 by relamine          #+#    #+#             */
/*   Updated: 2023/12/21 08:22:07 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 4
#endif


void f()
{
  system("leaks a.out");
}

static int reading(char **arr, int fd, char ** overneed)
{
  int i;
  int index;
  char *tmp;
  ssize_t byte_reading;

  i = 0;
  index = 0;
  byte_reading = read(fd, *arr, BUFFER_SIZE);
  if (byte_reading == -1)
      return (-1);
  else if (!byte_reading)
      return (0);
  char *chrs = ft_strchr(*arr, '\n');
  if (chrs)
  {
    tmp = *overneed;
    *overneed = ft_strjoin(tmp, chrs + 1);
    free(tmp);
    printf("----%s---",*overneed);
    tmp = *arr;
    *arr = ft_substr(*arr,0, (int)(chrs - *arr) + 1);
    free(tmp);
    return (1);
  }
  return(2);
}

char *get_next_line(int fd)
{
  char *arr;
  char *rs = NULL;

  static char *overneed = NULL;
  int check;

  char *s;
  arr = malloc(BUFFER_SIZE + 1);
  check = reading(&arr, fd, &overneed);
  rs = ft_strjoin(arr, NULL);
  free(arr);
  arr = NULL;
  while (check == 2)
  {
    arr = malloc(BUFFER_SIZE + 1);
    check = reading(&arr, fd, &overneed);
    s =rs;
    rs = ft_strjoin(s, arr);
    free(s);
    rs = NULL;
  }
  if (!check)
    return (rs);
  else if (check == -1)
    return (NULL);
  return (rs);
}


int main()
 {
  int fd = open("file.txt", O_RDONLY);
  if (fd == -1)
      return (-1);
  char *line = get_next_line(fd);
  printf("\n####%s####",line);
  // while (line)
  // {
  //   printf("%s",line);
  //   free(line);
  //   line = get_next_line(fd);
  // }
  // atexit(f);
 }
 
