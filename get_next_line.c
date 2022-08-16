/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 09:44:26 by tde-melo          #+#    #+#             */
/*   Updated: 2022/08/16 14:39:41 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *extra_char(char *str)
{
    int i;
    int j;
    char *remainder;

    if (!*str)
    {
        free(str);
        return (NULL);
    }
    i = 0;
    while (str[i])
    {
        if (str[i] == '\n')
        {
            i++;
            break;
        }
        i++;
    }
    j = 0;
    while (str[i])
    {
        j++;
        i++;
    }
    if (!(remainder = malloc((j + 1) * sizeof(char))))
        return (NULL);
    i = i - j;
    j = 0;
    while (str[i])
        remainder[j++] = str[i++];
    remainder[j] = 0;
    free(str);
    return (remainder);
}

char *get_line(char *str)
{
    int i;
    char *line;

    if (!*str)
        return (NULL);
    i = 0;
    while (str[i] && str[i] != '\n')
        i++;
    if (!(line = malloc((i + 2) * sizeof(char))))
        return (NULL);
    i = 0;
    while (*str && *str != '\n')
        line[i++] = *str++;
    if (*str == '\n')
        line[i++] = '\n';
    line[i] = 0;
    return (line);
}

char *read_line(char *str, int fd)
{
    char *buffer;
    ssize_t flag;

    if (!(buffer = malloc((BUFFER_SIZE + 1) * sizeof(char))))
        return (NULL);
    flag = 1;
    while (!ft_strchar(str, '\n') && flag)
    {
        flag = read(fd, buffer, BUFFER_SIZE);
        buffer[flag] = 0;
        if (flag == -1)
        {
            free(buffer);
            return (0);
        }
        str = ft_strjoin(str, buffer);
    }
    free(buffer);
    return (str);
}

char *get_next_line(int fd)
{
    static char *str;
    char *line;

    if (fd < 0 || fd > 8 || BUFFER_SIZE <= 0)
        return (NULL);
    str = read_line(str, fd);
    line = get_line(str);
    str = extra_char(str);
    return (line);
}

int main()
{
    int fd = open("file.txt", O_RDONLY);

    char *str= get_next_line(fd);
        printf("%s", str);

    // while (1)
    // {
    //     free(str);
    //     if (!*str)
    //         break;
    // }
}