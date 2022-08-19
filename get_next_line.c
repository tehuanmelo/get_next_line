/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 09:44:26 by tde-melo          #+#    #+#             */
/*   Updated: 2022/08/19 14:00:38 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extra_char(char *str)
{
	int		i;
	int		j;
	char	*remainder;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	j = ft_strlen(str) - i - 1;
	if (j < 0 || !*str)
	{
		free(str);
		return (NULL);
	}
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
	size_t	buffer_cast;

	buffer_cast = (size_t)BUFFER_SIZE;
	buffer = malloc((buffer_cast + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	flag = 1;
	while (!ft_strchar(str, '\n') && flag)
	{
		flag = read(fd, buffer, buffer_cast);
		if (flag == -1)
		{
			free(buffer);
			return (0);
		}
		buffer[flag] = 0;
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = read_line(str, fd);
	if (!str)
	{
		free(str);
		return (NULL);
	}
	line = get_line(str);
	str = extra_char(str);
	return (line);
}

// int main()
// {
//     int fd = open("file.txt", O_RDONLY);

//    char *str;

//     while (1)
//     {

//         str = get_next_line(fd);
//         if (!str){
// 			free(str);
//             break ;}
//         printf("%s", str);
//         free(str);

//     }
// }