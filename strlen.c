/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:59:18 by ramhouch          #+#    #+#             */
/*   Updated: 2022/10/15 02:26:26 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (s[n])
		n++;
	return (n);
}

void	print_error(char *str)
{
	int	i;

	i = 0;
	write(2, "zsh: command not found: ", 24);
	while (str[i] && str[i] != ' ')
	{
		write(2, str + i, 1);
		i++;
	}
	write(2, "\n", 1);
}
