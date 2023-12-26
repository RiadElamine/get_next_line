/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:15:45 by relamine          #+#    #+#             */
/*   Updated: 2023/12/26 11:23:48 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"


void f()
{
  system("leaks a.out");
}

char    *line_get(char **buffer)
{
    char *line;
    int  findnl;
    char *tmp;
    size_t len;

    findnl = ft_strchr(*buffer, '\n');
    if (findnl != -1)
    {
        line = ft_substr(*buffer, 0, findnl + 1);
        tmp = *buffer;
        len = ft_strlen(&(tmp[findnl + 1])); 
        if (len != 0)
            *buffer = ft_substr(tmp, findnl + 1, len);
        else
            return (free(tmp), *buffer = NULL, line);
        free(tmp);
    }
    else
    { 
        line = ft_strdup(*buffer);
        free(*buffer);
        *buffer = NULL;
    }
    return (line); 
}
char    *reading(char **buffer, int fd)
{
    int byte;
    char *arr;

    arr = malloc((size_t)BUFFER_SIZE + 1);
    byte = read(fd, arr, BUFFER_SIZE);
    if (byte == -1)
        return (free(arr), free(*buffer), NULL);
    while (byte > 0)
    {
        arr[byte] = '\0';

        *buffer = ft_strjoin(*buffer, arr);

        if  (ft_strchr(arr, '\n') != -1)
            break;

        byte = read(fd, arr, BUFFER_SIZE);
        if (byte == -1)
            return (free(arr), NULL);
    }
    return (free(arr), *buffer);
}
char    *get_next_line(int fd)
{

    static char *buffer;

    if (fd >= 0 && fd <= OPEN_MAX)
    {
        buffer = reading(&buffer, fd);
        if  (buffer)
            return (line_get(&buffer));
    }
    return (buffer);
}

    // if (fd < 0 || fd > OPEN_MAX)
    //     return (NULL);

// int main()
//  {
//     int fd = open("file.txt", O_RDONLY);
//     if (fd == -1)
//         return (-1);
    
//     char *line = get_next_line(fd);
//     printf("####%s####",line);
//     free(line);

//     close (fd);
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
//     atexit(f);
//     return (0);
//  }
 












//  char    *reading(char **buffer, int fd)
// {
//     int byte;
//     char *arr;

//     arr = malloc((size_t)BUFFER_SIZE + 1);
//     if (!arr)
//         return(free(*buffer), NULL);
//     byte = read(fd, arr, BUFFER_SIZE);
//     if (byte == -1)
//         return (free(arr), free(*buffer), NULL);
//     while (byte >= 0)
//     {
//         arr[byte] = '\0';
//         *buffer = ft_strjoin(*buffer, arr);
//         free(arr);
//         if (byte == 0 && !*buffer[0])
//             return (free(*buffer), NULL);
//         if  (ft_strchr(*buffer, '\n'))
//             break;
//         byte = read(fd, arr, BUFFER_SIZE);
//         if (byte == -1)
//         return (free(arr), free(*buffer), NULL);
//     }
//     return (*buffer);
// }