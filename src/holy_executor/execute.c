/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:58:11 by astavrop          #+#    #+#             */
/*   Updated: 2024/04/21 16:29:43 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/executor.h"
#include "../../lib/libft/libft.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define INVALID_CMD_ERR_MSG "Invalid command"

/**
 * @brief Searches for the binary executable file in the directories listed
 *        in the PATH environment variable.
 *
 * This function searches for the binary executable file corresponding
 * to the given simple command in the directories listed in the PATH
 * environment variable. If the binary executable file is found in any of the
 * directories, the function `bin_check` checks that found file is an
 * executable. If the binary executable file is not found in any directory,
 * the function returns.
 *
 * @param cmd Pointer to the simple command structure containing the details 
 *        of the command.
 */
void	find_bin(t_SimpleCommand *cmd)
{
	char	*env_path;
	char	**path_list;
	int		i;

	env_path = getenv("PATH");
	if (!env_path)
		return ;
	path_list = ft_split(env_path, ':');
	if (!path_list)
		return ;
	i = -1;
	while (path_list[++i])
	{
		if (bin_check(cmd, path_list[i]) == 0)
		{
			free_str_list(path_list);
			return ;
		}
	}
	free_str_list(path_list);
}

/**
 * @brief Sets up input and output redirection for a simple command,
 *        possibly involving pipes.
 *
 * This function sets up input and output redirection for a simple command,
 * taking into account whether it is part of the left or right command 
 * of a pipeline. It also handles the case when the command has its own 
 * file descriptors for input and output. The function redirects standard
 * input and output accordingly, allowing the command to receive input
 * from the previous command in the pipeline and send output to the
 * next command in the pipeline.
 *
 * @param cmd Pointer to the simple command structure containing the details
 *            of the command.
 * @param mode A character indicating the mode of the current pipe:
 *             - 'l' indicates that the current pipe is for the left command.
 *             - 'r' indicates that the current pipe is for the right command.
 */
void	set_pipes(t_SimpleCommand *cmd, int mode)
{
	if (mode == 'l')
	{
		if (cmd->pipefd[RDEND] >= 0)
			close(cmd->pipefd[RDEND]);
		if (cmd->in_fd == -1 && cmd->pipefd[RDEND] >= 0)
			dup2(cmd->pipefd[RDEND], STDIN_FILENO);
	}
	else if (mode == 'r')
	{
		if (cmd->pipefd[WREND] >= 0)
			close(cmd->pipefd[WREND]);
		if (cmd->in_fd == -1 && cmd->pipefd[RDEND] >= 0)
			dup2(cmd->pipefd[RDEND], STDIN_FILENO);
	}
	if (cmd->in_fd != -1)
		dup2(cmd->in_fd, STDIN_FILENO);
	if (cmd->out_fd != -1)
		dup2(cmd->out_fd, STDOUT_FILENO);
	else if (cmd->out_fd == -1 && cmd->pipefd[WREND] >= 0)
		dup2(cmd->pipefd[WREND], STDOUT_FILENO);
}

/**
 * @brief Executes a simple command.
 *
 * This function executes the given simple command in a child process.
 * It first forks a new process, then sets up input and output redirection
 * using the `set_pipes` function according to the specified mode. After
 * setting up the pipes, it checks if the command is valid using cmd_check.
 * If the command is valid, it searches for the binary executable file
 * using `find_bin`, prints the command details using print_command,
 * and attempts to execute the command using execve.
 * If the execution fails, it exits with an error message.
 *
 * @param cmd Pointer to the simple command structure containing the details
 *            of the command.
 * @param mode A character indicating the mode of the current pipe:
 *             - 'l' indicates that the current pipe is for the left command.
 *             - 'r' indicates that the current pipe is for the right command.
 * @return Returns the process ID (PID) of the child process.
 *         - Returns -1 if forking fails.
 */
int	cmd_exe(t_SimpleCommand *cmd, int mode)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		fork_fail();
	if (pid == 0)
	{
		set_pipes(cmd, mode);
		if (cmd_check(cmd) != 0)
			(perror(INVALID_CMD_ERR_MSG), exit(FAIL));
		find_bin(cmd);
		print_command(cmd);
		if (execve(cmd->bin, cmd->args, cmd->envp) == -1)
			exit(execution_fail(cmd->args[0]));
	}
	return (pid);
}
