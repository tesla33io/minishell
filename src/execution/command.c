/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:07:14 by astavrop          #+#    #+#             */
/*   Updated: 2024/07/27 15:40:28 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"
#include "../../include/builtins.h"

#include <curses.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> /* getenv() */

static void	setup_ipc(t_Command *cmd, int i, int pipefd[2][2], int num_cmds);

void	execute_command_in_child(t_Command *cmd, int pipefd[2][2],
		int i, int num_cmds)
{
	char	*bin;

	setup_ipc(cmd, i, pipefd, num_cmds);
	/* TODO: replace getenv with ft_getenv */
	if (is_builtin(cmd->bin_name))
		run_builtin(cmd);
	else
		bin = check_exec_binary(ft_getenv(cmd->envpv, "PATH"), cmd->bin_name);
	if (execve(bin, cmd->args, cmd->envpv) < 0)
		exit(execve_fail());
}

int	is_builtin(char *bin_name)
{
	return (ft_strcmp(bin_name, "echo") == 0 || ft_strcmp(bin_name, "cd") == 0
		|| ft_strcmp(bin_name, "env") == 0 || ft_strcmp(bin_name, "pwd") == 0
		|| ft_strcmp(bin_name, "export") == 0
		|| ft_strcmp(bin_name, "unset") == 0
		|| ft_strcmp(bin_name, "exit") == 0);
}

int	run_builtin(t_Command *cmd)
{
	if (ft_strcmp(cmd->bin_name, "echo") == 0)
		return (echo_builtin(cmd));
	else if (ft_strcmp(cmd->bin_name, "pwd") == 0)
		return (pwd_builtin(cmd));
	else if (ft_strcmp(cmd->bin_name, "env") == 0)
		return (env_builtin(cmd));
	else if (ft_strcmp(cmd->bin_name, "export") == 0)
		return (export_builtin(cmd));
	else if (ft_strcmp(cmd->bin_name, "unset") == 0)
		return (unset_builtin(cmd));
	else if (ft_strcmp(cmd->bin_name, "cd") == 0)
		return (cd_builtin(cmd));
	else
		return (0);
}

static void	setup_ipc(t_Command *cmd, int i, int pipefd[2][2], int num_cmds)
{
	if (cmd->in_fd != 0)
		dup2(cmd->in_fd, STDIN_FILENO);
	else if (i > 0)
		dup2(pipefd[(i - 1) % 2][0], STDIN_FILENO);
	if (cmd->out_fd != 1)
		dup2(cmd->out_fd, STDOUT_FILENO);
	else if (i < num_cmds - 1)
		dup2(pipefd[i % 2][1], STDOUT_FILENO);
	if (i > 0)
	{
		close(pipefd[(i - 1) % 2][0]);
		close(pipefd[(i - 1) % 2][1]);
	}
	if (i < num_cmds - 1)
	{
		close(pipefd[i % 2][0]);
		close(pipefd[i % 2][1]);
	}
	if (cmd->in_fd != 0)
		close(cmd->in_fd);
	if (cmd->out_fd != 1)
		close(cmd->out_fd);
}
