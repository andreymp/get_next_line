/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:56:16 by jobject           #+#    #+#             */
/*   Updated: 2021/10/15 20:31:14 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_after(char	*str)
{
	size_t	i;
	char	*res;

	i = 0;
	while (*(str + i) != '\n' && *(str + i))
		i++;
	if (*(str + i + 1))
	{
		res = (char *) malloc(ft_strlen(str) - i);
		ft_memcpy(res, str + i + 1, ft_strlen(str) - i);
		//free(str);
		return (res);
	}
	return (NULL);
}

char	*get_until(char	*str)
{
	int			i;
	char		*res;

	i = 0;
	while (*(str + i) != '\n' && *(str + i))
		i++;
	if (*(str + i))
	{
		res = (char *) malloc(i + 1);
		ft_memcpy(res, str, i + 1);
		//free(str);
		return (res);
	}
	return (NULL);
}

int	full_line(char	*str)
{
	int i;
	i = 0;
	while (*(str + i) && *(str + i) != '\n')
		i++;
	if (!*(str + i))
		return (0);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*res;
	char		*str;
	char		buf[BUFFER_SIZE + 1];
	int			r;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	r = 1;
	if (!res)
		res = ft_strdup("\0");
	while (r > 0 && !full_line(res))
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r <= 0)
			return (NULL);
		*(buf + r) = '\0';
		res = ft_strjoin(res, buf);
	}
	str = get_until(res);
	res = get_after(res);
	return (str);
}

 #include <fcntl.h>
/*
 int		main(void)
 {
 	int		fd;
 	char	*line;
	

 	fd = open("test.txt", O_RDONLY);
 	line = get_next_line(fd);	
	puts(line);
 	free(line);
 	line = get_next_line(fd);
	puts(line);
 	free(line);
 	line = get_next_line(fd);
 	puts(line);
 	free(line);
	// close(fd);
	while (1) ;
}
*//*
int		main(void)
{
	char	*line;

	while ((line = get_next_line(0)))
	{
		puts(line);
		free(line);
	}
	//free(line);
}
*/