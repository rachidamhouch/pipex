/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:11:21 by ramhouch          #+#    #+#             */
/*   Updated: 2022/11/30 01:14:43 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	run(char **cmds, char **env, int ac)
{
	int	i;
	int	pid;
	int	s;

	i = 3;
	s = 0;
	while (i < ac - 2)
	{
		reader(cmds[i], env);
		i++;
	}
	pid = fork();
	if (pid < 0)
	{
		perror("Fork");
		exit(10);
	}
	if (!pid)
		exec_cmd(cmds[ac - 2], env);
	while (wait(&s) != -1)
	{
		if (s != 0)
			exit(s);
	}
}

static void	help(int fd, char *limiter)
{
	char	*ptr;

	write(1, "heredoc> ", 9);
	ptr = get_next_line(0);
	while (1)
	{
		if (!ptr || (!ft_strncmp(limiter, ptr, ft_strlen(limiter))
				&& ptr[ft_strlen(limiter)] == '\n'))
		{
			free(ptr);
			break ;
		}
		write(fd, ptr, ft_strlen(ptr));
		free(ptr);
		write(1, "heredoc> ", 9);
		ptr = get_next_line(0);
	}
}

void	here_doc(char **av, char **env, int ac)
{
	int		pip[2];
	int		fd_out;

	check2(av, env, ac);
	pipe(pip);
	fd_out = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0600);
	if (fd_out < 0)
	{
		perror("OUTFILE");
		exit(9);
	}
	help(pip[1], av[2]);
	dup2(pip[0], 0);
	dup2(fd_out, 1);
	close(pip[0]);
	close(pip[1]);
	run(av, env, ac);
	close(fd_out);
	exit(0);
}
