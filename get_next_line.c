/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 23:05:27 by ramhouch          #+#    #+#             */
/*   Updated: 2022/10/20 21:43:32 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*all(int fd, char *left)
{
	char	*buffer;
	int		readed;

	readed = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (readed && !my_strchr(left, '\n'))
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[readed] = '\0';
		left = my_strjoin(left, buffer);
	}
	free(buffer);
	return (left);
}

static char	*get_line(char *line)
{
	int		i;
	char	*ptr;

	i = 0;
	if (!line)
		return (NULL);
	if (!line[i])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	ptr = malloc(i + 2);
	if (!ptr)
		return (NULL);
	my_memcpy(ptr, line, i);
	if (line[i] == '\n')
	{
		ptr[i] = '\n';
		ptr[i + 1] = '\0';
	}
	else
		ptr[i] = '\0';
	return (ptr);
}

static char	*ft_left(char *line)
{
	int		i;
	char	*ptr;

	i = 0;
	if (!line)
		return (NULL);
	if (!line[i])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	ptr = malloc(my_strlen(line) - i + 1);
	if (!ptr)
		return (NULL);
	my_memcpy(ptr, line + i + 1, my_strlen(line) - i);
	ptr[my_strlen(line) - i] = '\0';
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char	*left;
	char		*line;
	char		*next_line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	line = all(fd, left);
	next_line = get_line(line);
	left = ft_left(line);
	free(line);
	return (next_line);
}
