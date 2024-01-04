/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:15:45 by relamine          #+#    #+#             */
/*   Updated: 2024/01/02 00:26:47 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

static char    *ft_line_get(char **buffer)
{
    char *line;
    int  findnl;
    char *tmp;
    size_t len;

    findnl = ft_strchr(*buffer, '\n');
    if (findnl == -1)
    {
        line = ft_strdup(*buffer);
        if(line)
            free(*buffer);
        return (*buffer = NULL, line);
    }
    line = ft_substr(*buffer, 0, findnl + 1);
    if (!line)
        return (free(*buffer), *buffer = NULL, NULL);
    tmp = *buffer;
    len = ft_strlen(&(tmp[findnl + 1])); 
    if (len == 0)
        return (free(tmp), *buffer = NULL, line);
    *buffer = ft_substr(tmp, findnl + 1, len);
    return (free(tmp), line); 
}
static char    *ft_reading(char *buffer, int fd)
{
    ssize_t byte;
    char *arr;

    arr = malloc((size_t)BUFFER_SIZE + 1);
    if (!arr)
        return (free(buffer), NULL);
    byte = read(fd, arr, BUFFER_SIZE);
    if (byte == -1) 
        return (free(arr), free(buffer), NULL);
    while (byte > 0)
    {
        arr[byte] = '\0';
        buffer = ft_strjoin(buffer, arr);
        if (!buffer)
            return (NULL);
        if  (ft_strchr(arr, '\n') != -1)
            break;
        byte = read(fd, arr, BUFFER_SIZE);
        if (byte == -1)
            return (free(arr), NULL);
    }
    return (free(arr), buffer);
}
char    *get_next_line(int fd)
{

    static char *buffer;

    if ((fd >= 0 && fd <= OPEN_MAX ) && BUFFER_SIZE >= 0)
    {
        buffer = ft_reading(buffer, fd);
        if  (buffer)
            return (ft_line_get(&buffer));
    }
    return (NULL);
}

// void f()
// {
//   system("leaks a.out");
// }

// int main()
//  {
    
//     int fd = open("file.txt", O_RDWR);
//     if (fd == -1)
//         return (-1);
//     // write(fd, "ABCDHAYOUB", 10);
//     // lseek(fd, 0, SEEK_SET);
//     // lseek(fd, -5, SEEK_END);
//     char *line = get_next_line(fd);
//     printf("####%s####",line);
//     free(line);

//     // close (fd);
//     line = get_next_line(fd);
//     printf("\n####%s####",line);
//     free(line);
    
//     // line = get_next_line(fd);
//     // printf("\n####%s####",line);
//     // free(line);
    
//     // line = get_next_line(fd);
//     // printf("\n####%s####",line);
//     // free(line);
    
//     // line = get_next_line(fd);
//     // printf("\n####%s####",line);
   
//     // line = get_next_line(fd);
//     // printf("\n####%s####",line);

// // free(line);
//     // while (line != NULL)
//     // {
//     //     printf("%s",line);
//     //     free(line);
//     //     line = get_next_line(fd);
//     // }
//     // atexit(f);
//     return (0);
//  }
 
