/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 09:44:26 by tde-melo          #+#    #+#             */
/*   Updated: 2022/08/18 23:32:55 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*extra_char(char *str)
{
	int		i;
	int		j;
	char	*remainder;

	if (!*str)
	{
		free(str);
		return (NULL);
	}
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	j = ft_strlen(str) - i - 1;
	remainder = malloc((j + 1) * sizeof(char));
	if (!remainder)
		return (NULL);
	if (str[i] == '\n')
		i++;
	j = 0;
	while (str[i])
		remainder[j++] = str[i++];
	remainder[j] = 0;
	free(str);
	return (remainder);
}

char	*get_line(char *str)
{
	int		i;
	char	*line;

	if (!*str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	line = malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (*str && *str != '\n')
		line[i++] = *str++;
	if (*str == '\n')
		line[i++] = '\n';
	line[i] = 0;
	return (line);
}

char	*read_line(char *str, int fd)
{
	char	*buffer;
	ssize_t	flag;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
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

char	*get_next_line(int fd)
{
	static char	*str[256];
	char		*line;

	if (fd < 0 || fd > 8 || BUFFER_SIZE <= 0)
		return (NULL);
	str[fd] = read_line(str[fd], fd);
	line = get_line(str[fd]);
	str[fd] = extra_char(str[fd]);
	return (line);
}

// int main()
// {
//     int fd1 = open("file1.txt", O_RDONLY);
//     int fd2 = open("file2.txt", O_RDONLY);
//     int fd3 = open("file3.txt", O_RDONLY);

//    char *str1 = get_next_line(fd1);
//    char *str2 = get_next_line(fd2);
//    char *str3 = get_next_line(fd3);

//    printf("%s", str1);
//    printf("%s", str2);
//    printf("%s", str3);

//    free(str1);
//    free(str2);
//    free(str3);
   
//    str1 = get_next_line(fd1);
//    str2 = get_next_line(fd2);
//    str3 = get_next_line(fd3);

//    printf("%s", str1);
//    printf("%s", str2);
//    printf("%s", str3);

//    free(str1);
//    free(str2);
//    free(str3);
   
//    str1 = get_next_line(fd1);
//    str2 = get_next_line(fd2);
//    str3 = get_next_line(fd3);

//    printf("%s", str1);
//    printf("%s", str2);
//    printf("%s", str3);

//    free(str1);
//    free(str2);
//    free(str3);

// }