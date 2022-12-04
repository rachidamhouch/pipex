/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:08:44 by ramhouch          #+#    #+#             */
/*   Updated: 2022/11/30 01:10:19 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*str_join(char *s1, char *s2)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*ptr;

	len = ft_strlen(s1) + ft_strlen(s2) + 2;
	ptr = malloc(len);
	i = 0;
	j = 0;
	while (i < ft_strlen(s1))
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i++] = '/';
	while (j < ft_strlen(s2) && s2[j] != ' ')
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static void	find_file(char **paths, char **cmd, int nb)
{
	int		i;
	char	*ptr;

	i = 0;
	if (!access(cmd[nb], X_OK))
		return ;
	while (paths[i])
	{
		ptr = str_join(paths[i], cmd[nb]);
		if (!access(ptr, X_OK))
		{
			free(ptr);
			i = 0;
			break ;
		}
		free(ptr);
		i++;
	}
	if (i)
	{
		print_error(cmd[nb]);
		exit(127);
	}
}

char	*get_paths(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
			return (env[i]);
		i++;
	}
	return (0);
}

void	check(char **av, char **env, int ac)
{
	char	**paths;
	int		i;
	char	*ptr;
	int		n;

	n = 2;
	ptr = get_paths(env);
	paths = ft_split(ptr + 5, ':');
	i = 0;
	if (access(av[1], F_OK))
	{
		perror("Infile");
		exit(1);
	}
	while (n < ac - 1)
	{
		find_file(paths, av, n);
		n++;
	}
}

void	check2(char **av, char **env, int ac)
{
	char	**paths;
	int		i;
	char	*ptr;
	int		n;

	n = 3;
	ptr = get_paths(env);
	paths = ft_split(ptr + 5, ':');
	i = 0;
	while (n < ac - 1)
	{
		find_file(paths, av, n);
		n++;
	}
}
