/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:15:45 by relamine          #+#    #+#             */
/*   Updated: 2023/12/18 23:15:10 by relamine         ###   ########.fr       */
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


// This For Reading From Overneed variable
static void rd_from_over(char *overneed, char *re)
{
  char *tmp = NULL;

  if (re != NULL)
  {
    char *chr_nl = ft_strchr(re, '\n');
    if (chr_nl)
    {
      int size = (int)(chr_nl - re) + 1;
      ft_strlcpy(re, overneed, sizeof(size));
      tmp = overneed;
      overneed = ft_substr(overneed, (int)(chr_nl - re) + 1, sizeof(overneed));
      free(tmp);
    }
    else
    {
      ft_strlcpy(re, overneed, sizeof(overneed));
    }
    
  }
}
char *get_next_line(int fd) {
  int index = 0;
  static char *overneed = NULL;
  char *arr;
  char *rs = NULL;
  char *tmp = NULL;
  static int count = 0;
  int checkline = 0;

  arr = malloc(BUFFER_SIZE + 1);
  ssize_t byte_reading;

  checkline = count;
  while (index < BUFFER_SIZE)
  {
    if (overneed == NULL)
    {
      byte_reading = read(fd, arr, BUFFER_SIZE);
      if (byte_reading == -1)
        return (NULL);
      else if (!byte_reading)
        break;
    }
    else
    {
      byte_reading = read(fd, arr, BUFFER_SIZE);
      if (byte_reading == -1)
        return (NULL);

      if(count == checkline)
      {
        char *addfront = malloc(BUFFER_SIZE + 1);
        rd_from_over(overneed, addfront);
        tmp = arr;
        arr = ft_strjoin(addfront,tmp);
        free(tmp);
        free(addfront);
      }
      checkline++;
      if (!byte_reading)
        break;
    }
    // this for to end the process of reading line && save overreding word in overneed
    char *chrs = ft_strchr(arr, '\n');
    if (chrs)
    {
      index = (int)(chrs - arr);
      if (overneed == NULL && arr)
        overneed = ft_substr(arr,index + 1, BUFFER_SIZE);
      else if(arr)
      {
        tmp = overneed;
        overneed = ft_strjoin(tmp,arr);
        free(tmp);
      }
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
      tmp = rs;
      rs = ft_strjoin(tmp,arr);
      free(tmp);

      //initialisation
      index = 0;
      free(arr);
      arr = malloc(BUFFER_SIZE + 1);
    }
  }
  count++;
  return (rs);
}


int main()
 {
  
  int fd = open("file.txt", O_RDONLY);
  char *line = get_next_line(fd);
  printf("%s",line);
  // while (line)
  // {
  //   printf("%s",line);
  //   free(line);
  //   line = get_next_line(fd);
  // }
  // atexit(f);
 }
 
