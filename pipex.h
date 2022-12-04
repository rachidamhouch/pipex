/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:16:06 by ramhouch          #+#    #+#             */
/*   Updated: 2022/11/19 11:16:07 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>
# include <errno.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

void	check(char **av, char **env, int ac);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*get_paths(char **env);
char	*str_join(char *s1, char *s2);
void	print_error(char *str);
int		exec_cmd(char *cmd, char **env);
void	reader(char *cmd, char **env);
void	here_doc(char **av, char **env, int ac);
char	*get_next_line(int fd);
size_t	my_strlen(const char *s);
char	*my_strjoin(char *s1, char *s2);
char	*my_strchr(const char *s, int c);
void	*my_memcpy(void *dst, const void *src, size_t n);
void	check2(char **av, char **env, int ac);

#endif
