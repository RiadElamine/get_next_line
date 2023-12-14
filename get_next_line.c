/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:15:45 by relamine          #+#    #+#             */
/*   Updated: 2023/12/14 23:34:25 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"


#define buffer_size 9

// void f()
// {
//   system("leaks a.out");
// }

char *get_next_line(int fd) {
  static int count = 0;
  int index = 1;
  char *arr;
  char *q;
  char *tmp;


  arr = malloc(buffer_size + 1);
  ssize_t byte_reading;

  while (index <= buffer_size)
  {
    byte_reading = read(fd, &arr[index - 1], 1);
    if (byte_reading == -1)
    {
      perror ("Error in reading file");
      return (NULL);
    }
    else if (byte_reading == 0)
    {
      return (NULL);
    }

    if (arr[index - 1] == '\n')
    {
      arr[index] = '\0';
      q = ft_strjoin(q,arr);
      free(arr);
      index++;
      break;
    }
    index++;
    if (index > buffer_size)
    {
      arr[buffer_size] = '\0';
      if (count == 0)
        {
          q = ft_strjoin(arr, NULL);
          count++;
        }
      else
        {
          tmp = q;
          q = ft_strjoin(tmp,arr);
          free(tmp);
          count++;
        }
      index = 1;
      free(arr);
      arr = malloc(buffer_size + 1);
    }
  }
  return (q);
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
  // get_next_line(fd);

  close(fd);
  // atexit(f);
  return (0);
 }
