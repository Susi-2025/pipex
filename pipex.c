/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinguyen <vinguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:11:42 by vinguyen          #+#    #+#             */
/*   Updated: 2025/06/18 13:13:30 by vinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	int		pipefd[2];
	pid_t	pid;

	if (ac != 5)
		exit(EXIT_FAILURE);
	else
	{
		if (pipe(pipefd) == -1)
			return (EXIT_FAILURE);
		pid = fork();
		if (pid == -1)
			return (EXIT_FAILURE);
		else if (pid == 0)
			children_process(av, envp, pipefd);
		else
		{
			waitpid(pid, NULL, 0);
			parent_process(av, envp, pipefd);
		}
	}
	return (EXIT_SUCCESS);
}

void	children_process(char **av, char **envp, int pipefd[2])
{
	int	fd;

	printf("Children Process\n");
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error on open input file\n");
		return ;
	}
	printf("Value of fd and pipefd[1]: %d %d \n", fd, pipefd[1]);
	dup2(fd, STDIN_FILENO);
	close(fd);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[0]);
	close(pipefd[1]);
	execute_cmd(av[2], envp);
	perror("execve failed");
	exit(EXIT_FAILURE);
}

void	parent_process(char **av, char **envp, int pipefd[2])
{
	int	fd;

	printf("Parent Process\n");
	fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return ;
	dup2(pipefd[0], STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	close(pipefd[1]);
	close(pipefd[0]);
//	write(STDOUT_FILENO, "test output2 \n", 14);
	execute_cmd(av[3], envp);
}

void	execute(char *cmd, char **envp)
{
	printf("%s\n", cmd);
	while (*envp)
	{
		printf("%s\n", envp[0]);
		envp++;
	}
}
