/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 09:43:55 by tde-melo          #+#    #+#             */
/*   Updated: 2022/08/17 11:05:10 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchar(char *str, int c)
{
	int	len;
	int	i;

	len = ft_strlen(str);
	i = 0;
	if (!str)
		return (NULL);
	while (i <= len)
	{
		if (str[i] == c)
		{
			return (&str[i]);
		}
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	char	*new;
	int		i;

	if (!s1)
	{
		str = malloc(sizeof(char));
		if (!str)
			return (NULL);
		s1 = str;
	}
	new = malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (*s2)
		new[i++] = *s2++;
	new[i] = 0;
	free(s1);
	return (new);
}
