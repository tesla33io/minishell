/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:58:11 by astavrop          #+#    #+#             */
/*   Updated: 2024/04/02 14:19:21 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/executor.h"
#include "../../lib/libft/libft.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define INVALID_CMD_ERR_MSG "Invalid command"

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


/*******************************************************************************
 * Modes:                                                                      *
 * `l` - indicates that current pipe is for left command of the pipeline       *
 * `r` - indicates that current pipe is for right command of the pipeline      *
 ******************************************************************************/
void	set_pipes(t_SimpleCommand *cmd, int mode)
{
	if (mode == 'l')
	{
		if (cmd->pipefd[RDEND] >= 0)
			close(cmd->pipefd[RDEND]);
		if (cmd->in_fd != -1)
			dup2(cmd->in_fd, STDIN_FILENO);
		if (cmd->out_fd != -1)
			dup2(cmd->out_fd, STDOUT_FILENO);
		else if (cmd->out_fd == -1 && cmd->pipefd[WREND] >= 0)
			dup2(cmd->pipefd[WREND], STDOUT_FILENO);
	}
	else if (mode == 'r')
	{
		if (cmd->pipefd[WREND] >= 0)
			close(cmd->pipefd[WREND]);
		if (cmd->in_fd != -1)
			dup2(cmd->in_fd, STDIN_FILENO);
		else if (cmd->in_fd == -1 && cmd->pipefd[RDEND] >= 0)
			dup2(cmd->pipefd[RDEND], STDIN_FILENO);
		if (cmd->out_fd != -1)
			dup2(cmd->out_fd, STDOUT_FILENO);
	}
}

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
			exit(execution_fail(cmd->bin));
	}
	return (pid);
}
