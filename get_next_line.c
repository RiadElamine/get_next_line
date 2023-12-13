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

#define buffer_size 10

// void f()
// {
//   system("leaks a.out");
// }
char *get_next_line(int fd) {
  char *array = malloc(buffer_size);
  ssize_t byte_reading = read(fd, array, buffer_size);
  if (byte_reading == -1)
  {
    perror ("Error in reading file");
    return (NULL);
  }
  else if (byte_reading == 0)
    return (NULL);
  close(fd);
  return (array);
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
  // atexit(f);
  return (0);
 }