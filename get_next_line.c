/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 12:25:28 by tde-melo          #+#    #+#             */
/*   Updated: 2022/08/10 16:48:41 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define     BUFFER_SIZE 7

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == (unsigned char)c)
			return (&((char *)s)[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	length;
	int		i;

	if (!(s1 && s2))
		return (NULL);
	length = ft_strlen(s1) + ft_strlen(s2);
	new = malloc((length + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (*s1)
		new[i++] = *s1++;
	while (*s2)
		new[i++] = *s2++;
	new[i] = 0;
	return (new);
}

//#######################################################//
//###################### MAIN FUNCTIONS ################//
//#####################################################//

char *read_line(int fd, char *str)
{
    char *buffer;
    ssize_t reading_flag;

    reading_flag = 1;
    if(!(buffer = calloc(BUFFER_SIZE + 1, sizeof(char))))
        return (NULL);
    while (!ft_strchr(buffer, '\n') && reading_flag)
    {
        reading_flag = read(fd, buffer, BUFFER_SIZE);
        str = ft_strjoin(str, buffer);
    }
    free(buffer);
    return(str);
}

char *get_line(char *str)
{
	char *new;
	int i;

	i = 0;
	while (str[i])
	{
		i++;
		if (str[i++] == '\n')
			break;	
	}
	if (!(new = calloc((i + 1), sizeof(char))))
		return (NULL);
	i = 0;
	while (*str != '\n' && *str != '\0')
		new[i++] = *str++;
	
	new[i] = '\n';
	return (new);
	
}

char *get_next_line(int fd)
{
    static char *str = "";
	char *line;
	
    str = read_line(fd, str);
	line = get_line(str);
	while (*str == '\0' || *str != '\n')
		str++;
	str++;
	free(line);
    return (line);
}

int main()
{
    int fd = open("file.txt", O_RDONLY);
	
    char *str = get_next_line(fd);
    printf("%s", str);
	
    str = get_next_line(fd);
    printf("%s", str);
	
    str = get_next_line(fd);
    printf("%s", str);
	
    close(fd);
    return 0;
}