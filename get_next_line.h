/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:56:19 by jobject           #+#    #+#             */
/*   Updated: 2021/10/13 20:41:44 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char	*str);
void	*ft_memcpy(void	*dest, const void	*src, size_t	num);
void	*ft_memmove(void	*dest, const void	*src, size_t	num);
char	*ft_strjoin(char const	*s1, char const	*s2);
char	*ft_strdup(const char	*str);
char	*ft_strchr(const char	*str, int code);

#endif