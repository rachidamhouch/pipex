/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:15:12 by ramhouch          #+#    #+#             */
/*   Updated: 2022/11/30 01:18:30 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	run(char **cmds, char **env)
{
	int	pid;
	int	s;

	s = 0;
	reader(cmds[2], env);
	pid = fork();
	if (pid < 0)
	{
		perror("Fork");
		exit(10);
	}
	if (!pid)
		exec_cmd(cmds[3], env);
	while (wait(&s) != -1)
	{
		if (s != 0)
			exit(s + 128);
	}
}

int	main(int ac, char **av, char **envp)
{
	int	fd_in;
	int	fd_out;

	if (ac == 5)
	{
		check(av, envp, ac);
		fd_in = open(av[1], O_RDONLY);
		fd_out = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0600);
		if (fd_in < 0)
			perror("INFILE");
		if (fd_out < 0)
			perror("OUTFILE");
		if (fd_in < 0 || fd_out < 0)
			exit(9);
		dup2(fd_in, 0);
		dup2(fd_out, 1);
		run(av, envp);
		close(fd_in);
		close(fd_out);
		return (0);
	}
	else
		write(2, "Invalid number of arguments.\n", 29);
	return (1);
}
