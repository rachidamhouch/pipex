/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:11:53 by ramhouch          #+#    #+#             */
/*   Updated: 2022/11/30 01:14:35 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	run(char **cmds, char **env, int ac)
{
	int	i;
	int	pid;
	int	s;

	i = 2;
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

static void	help(int fd_in, int fd_out)
{
	dup2(fd_in, 0);
	dup2(fd_out, 1);
	close(fd_in);
	close(fd_out);
}

int	main(int ac, char **av, char **envp)
{
	int	fd_in;
	int	fd_out;

	if (ac >= 5)
	{
		if (!ft_strncmp("here_doc", av[1], ft_strlen(av[1])))
			here_doc(av, envp, ac);
		check(av, envp, ac);
		fd_in = open(av[1], O_RDONLY);
		fd_out = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0600);
		if (fd_in < 0)
			perror("INFILE");
		if (fd_out < 0)
			perror("OUTFILE");
		if (fd_in < 0 || fd_out < 0)
			exit(9);
		help(fd_in, fd_out);
		run(av, envp, ac);
		return (0);
	}
	else
		write(2, "Invalid number of arguments.\n", 29);
	return (1);
}
