/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 03:05:40 by ramhouch          #+#    #+#             */
/*   Updated: 2022/10/21 00:02:04 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	count_word(char *str, char c)
{
	int	len;
	int	word;
	int	i;
	int	count;

	len = 0;
	word = 1;
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			word = 1;
		else
		{
			if (word == 1)
				count++;
			word = 0;
		}
		i++;
	}
	return (count);
}

static char	*ft_dup(char *str, char c, int *index)
{
	char	*ptr;
	int		count;
	int		in;
	int		i;

	count = 0;
	i = 0;
	while (str[*index] == c && str[*index])
		(*index)++;
	in = *index;
	while (str[*index] != c && str[*index])
	{
		count++;
		(*index)++;
	}
	ptr = malloc(count + 1);
	if (!ptr)
		return (0);
	while (i < count)
		ptr[i++] = str[in++];
	ptr[i] = '\0';
	return (ptr);
}

static char	**freetabe(char **ptr, int i)
{
	int	n;

	n = 0;
	while (n < i)
	{
		free(ptr[n]);
		n++;
	}
	free(ptr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		count;
	int		i;
	int		index;
	int		a;

	a = 0;
	if (!s)
		return (0);
	index = 0;
	i = 0;
	count = count_word((char *)s, c);
	ptr = malloc(sizeof(char *) * (count + 1));
	if (!ptr)
		return (0);
	while (i < count)
	{
		ptr[i] = ft_dup((char *)s, c, &index);
		if (!ptr[i])
			return (freetabe(ptr, i));
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}
