/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 09:44:35 by tde-melo          #+#    #+#             */
/*   Updated: 2022/08/16 12:04:51 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 2
#endif

int ft_strlen(char *str);
char *ft_strchar(char *str, int c);
char *ft_strjoin(char *s1, char *s2);
char *get_next_line(int fd);

#endif