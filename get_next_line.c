/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:15:45 by relamine          #+#    #+#             */
/*   Updated: 2023/12/21 08:14:09 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 4
#endif


// void f()
// {
//   system("leaks a.out");
// }
static void initialization(char **tbl, int rs)
{
    if (rs)
    {
        int i;
        char *tb;

        i = 0;
        tb = *tbl;
        while (tb[i])
        {
            tb[i] = '\0';
            i++;
        }
    }
    free(*tbl);
    *tbl = NULL;
}
static int reading(char **arr, char **rs, int fd)
{
    ssize_t byte_reading;
    char *tmp;

    tmp = NULL;
    byte_reading = read(fd, *rs, BUFFER_SIZE);
    if (byte_reading == -1)
        return (-1);
    char *chrs = ft_strchr(*rs, '\n');
    if (chrs)
    {
        tmp = *arr;
        *arr = ft_strjoin(*arr,*rs);
        initialization(&tmp, 0);
        initialization(rs, 1);
        *rs = ft_substr(*arr, 0, ft_strlen(*arr) - ft_strlen(ft_strchr(*arr, '\n') + 1));
        tmp = *arr;
        *arr = ft_substr(*arr, (int)(ft_strchr(*arr, '\n') - *arr) + 1, ft_strlen(ft_strchr(*arr, '\n') + 1));
        initialization(&tmp, 0);
        return (-2);
    }
    else if (byte_reading == 0)
    {
        initialization(rs, 1);
        return (0);
    }
    tmp = *arr;
    *arr = ft_strjoin(*arr,*rs);
    initialization(&tmp, 0);
    initialization(rs, 1);
    return (byte_reading);
}

char *get_next_line(int fd)
{
    ssize_t byte_reading;
    static char *arr;
    char *rs;


    rs = malloc(BUFFER_SIZE + 1);
    rs[BUFFER_SIZE] = '\0';
    byte_reading = reading(&arr, &rs, fd);
    if (byte_reading == -1)
        return (NULL);
    while (byte_reading > 0)
    {
        rs = malloc(BUFFER_SIZE + 1);
        rs[BUFFER_SIZE] = '\0';
        byte_reading = reading(&arr, &rs, fd);
    }
    if (byte_reading == -1)
        return (NULL);
    if (byte_reading == -2)
    {
        return (rs);
    }
    return (arr);
}


// int main()
//  {
//     int fd = open("file.txt", O_RDONLY);
//     if (fd == -1)
//         return (-1);
//     char *line = get_next_line(fd);
//     printf("\n####%s####",line);
//     free(line);
//     line = get_next_line(fd);
//     printf("\n####%s####",line);
//     free(line);
//     line = get_next_line(fd);
//     printf("\n####%s####",line);
//     free(line);
// // free(line);
//     // while (line)
//     // {
//     //     printf("%s",line);
//     //     free(line);
//     //     line = get_next_line(fd);
//     // }
//     atexit(f);
//  }
 