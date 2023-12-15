/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:15:45 by relamine          #+#    #+#             */
/*   Updated: 2023/12/15 23:44:18 by relamine         ###   ########.fr       */
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

char *get_next_line(int fd) {
  int check = 0;
  int index = 0;
  static char *overneed = NULL;
  // static int count = 0;
  char *arr;
  char *rs = NULL;
  char *tmp = NULL;



  arr = malloc(BUFFER_SIZE + 1);
  ssize_t byte_reading;

  while (index < BUFFER_SIZE)
  {
    byte_reading = read(fd, arr, BUFFER_SIZE);
    if (byte_reading == -1)
    {
      perror ("Error in reading file");
      return (NULL);
    }
    else if (byte_reading == 0)
      return (NULL);

    char *chrs = ft_strchr(arr, '\n');
    if (chrs)
    {
      index = (int)(chrs - arr);
      overneed = ft_substr(arr,index + 1, BUFFER_SIZE);
      arr[index + 1] = '\0';
      tmp = rs;
      rs = ft_strjoin(tmp,arr);
      free(arr);
      if (tmp)
        free(tmp);
      break;
    }
    
    index = BUFFER_SIZE;
    //this for complete process of reading line
    if (index == BUFFER_SIZE)
    {
      arr[BUFFER_SIZE] = '\0';
      if (check == 0)
      {
        rs = ft_strjoin(arr, NULL);
        check = 1;
      }
      else
      {
        tmp = rs;
        rs = ft_strjoin(tmp,arr);
        free(tmp);
      }
      //initialisation
      index = 0;
      free(arr);
      arr = malloc(BUFFER_SIZE + 1);
    }
  }
  return (rs);
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
  printf("%s",get_next_line(fd));
  // get_next_line(fd);

  close(fd);
  atexit(f);
  return (0);
 }
