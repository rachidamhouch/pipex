/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 08:41:39 by ramhouch          #+#    #+#             */
/*   Updated: 2022/11/30 01:14:15 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	reader(char *cmd, char **env)
{
	int	pid;
	int	pipefd[2];

	pipe(pipefd);
	pid = fork();
	if (pid < 0)
	{
		perror("Fork");
		exit(10);
	}
	if (!pid)
	{
		dup2(pipefd[1], 1);
		close(pipefd[0]);
		close(pipefd[1]);
		exec_cmd(cmd, env);
	}
	dup2(pipefd[0], 0);
	close(pipefd[1]);
	close(pipefd[0]);
}
