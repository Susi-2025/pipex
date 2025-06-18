/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinguyen <vinguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:30:57 by vinguyen          #+#    #+#             */
/*   Updated: 2025/06/18 12:23:26 by vinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <err.h>
# include <sys/wait.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>

void	children_process(char **av, char **envp, int pipefd[2]);
void	parent_process(char **av, char **envp, int pipefd[2]);
void	execute(char *cmd, char **envp);
void	execute_cmd(char *cmd, char **envp);
char	**find_path(char **envp);
char	*find_path_for_cmd(char **paths, char *cmd);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
#endif
