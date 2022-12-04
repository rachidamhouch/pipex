/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:20:15 by ramhouch          #+#    #+#             */
/*   Updated: 2022/12/01 01:29:12 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exec_cmd(char *cmd, char **env)
{
	char	**paths;
	int		i;
	char	*ptr;
	char	**par;

	ptr = get_paths(env);
	paths = ft_split(ptr + 5, ':');
	par = ft_split(cmd, ' ');
	i = 0;
	if (!access(cmd, X_OK))
		execve(cmd, par, env);
	while (paths[i])
	{
		ptr = str_join(paths[i], cmd);
		if (!access(ptr, X_OK))
			break ;
		i++;
	}
	execve(ptr, par, env);
	return (127);
}
