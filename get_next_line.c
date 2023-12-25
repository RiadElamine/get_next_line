/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:15:45 by relamine          #+#    #+#             */
/*   Updated: 2023/12/25 11:14:35 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"


// void f()
// {
//   system("leaks a.out");
// }

char    *line_get(char **buffer)
{
    char *line;
    char *findnl;
    char *tmp;

    findnl = ft_strchr(*buffer, '\n');
    if (findnl)
    {
        line = ft_substr(*buffer, 0, (int)(findnl - *buffer) + 1);
        tmp = *buffer;
        *buffer = ft_substr(*buffer, (int)(findnl - *buffer) + 1, ft_strlen(findnl + 1));
        free(tmp);
        if (!**buffer)
        {
            free(*buffer);
            *buffer = NULL;
        }
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
    char *tmp;

    byte = 1;
    while (byte > 0)
    {
        arr = malloc((size_t)BUFFER_SIZE + 1);
        byte = read(fd, arr, BUFFER_SIZE);
        if (byte == -1)
            return (free(arr), free(*buffer), NULL);
        arr[byte] = '\0';
        tmp = *buffer;
        *buffer = ft_strjoin(*buffer, arr);
        if (arr)
        {
            free(tmp);
            free(arr);
        }
        if (byte == 0 && !tmp)
            return (free(*buffer), NULL);
        if  (ft_strchr(*buffer, '\n'))
            byte = 0;
    }
    return (*buffer);
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
    return (NULL);
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
//     // atexit(f);
//     return (0);
//  }
 
