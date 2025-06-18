/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinguyen <vinguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 10:53:07 by vinguyen          #+#    #+#             */
/*   Updated: 2025/06/18 13:18:23 by vinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_cmd(char *cmd, char **envp)
{
	char	**paths;
	char	*path_for_cmd;
	char	**cmd_for_exe;

	paths = find_path(envp);
	cmd_for_exe = ft_split(cmd, ' ');
	path_for_cmd = find_path_for_cmd(paths, cmd_for_exe[0]);
	execve(path_for_cmd, cmd_for_exe, envp);
}

char	**find_path(char **envp)
{
	char	*origin_path;
	char	**paths;
	int		i;

	i = 0;
	origin_path = NULL;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5) != NULL)
		{
			origin_path = envp[i] + 5;
			break ;
		}
		i++;
	}
	if (origin_path == NULL)
		return (NULL);
	paths = ft_split(origin_path, ':');
	return (paths);
}

char	*find_path_for_cmd(char **paths, char *cmd)
{
	int		i;
	char	*new_path;
	char	*temp;

	i = 0;
	new_path = NULL;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		new_path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(new_path, F_OK) == 0)
			return (new_path);
		i++;
	}
	return (new_path);
}
