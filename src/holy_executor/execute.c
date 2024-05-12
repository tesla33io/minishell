/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:59:25 by astavrop          #+#    #+#             */
/*   Updated: 2024/05/12 15:05:04 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/executor.h"
#include "../../include/builtins.h"
#include "../../lib/libft/libft.h"

#include <unistd.h> /* pid_t, fork */
#include <stdlib.h>

// static void	setup_ipc(t_SimpleCommand *cmd);

/*
 * Check the command if it's:
 * - built-in
 * - binary on $PATH
 * - local binary
 * And runs it
 */
int	try_execute(t_SimpleCommand *cmd)
{
	pid_t	pid;

	if (is_builtint(cmd->bin, (char *[]){"echo", "cd", "pwd", "export", "unset",
				"env", "exit", NULL}))
		pid = run_builtin(cmd);
	else if (ft_strncmp(cmd->bin, "./", 2) == 0)
	{
		if (check_command(&cmd, true) != SUCCESS)
			return (FATAL_ERROR);
		pid = execute_command(cmd);
	}
	else
	{
		if (check_command(&cmd, true) != SUCCESS)
			return (FATAL_ERROR);
		pid = execute_command(cmd);
	}
	return (pid);
}

/*
 * executes a command and
 * returns an id of child process
 */
int	execute_command(t_SimpleCommand *cmd)
{
	pid_t	pid;
	char	**envp;

	pid = fork();
	if (pid < 0)
		fork_fail();
	if (pid == 0)
	{
		close(cmd->in_fd);
		dup2(cmd->out_fd, STDOUT_FILENO);
		envp = envp_ht_to_str_array(cmd->envp_ht);
		if (execve(cmd->bin, cmd->args, envp) < 0 && (free(envp), 1))
			execution_fail(cmd->args[0]);
	}
	return (pid);
}

int		cmd_exe(t_SimpleCommand *cmd, int mode)
{
	(void)cmd;
	return (mode);
}

/*
 * setup Inter Process Comunication
 *
 * if pipefd[0] == 1 && pipefd[1] == 0
 *		the command is first
 * else if pipefd[1] == 1 && pipefd[0] == 1
 *		the command is last
 * else
 *		the command is in the middle
 *
static void	setup_ipc(t_SimpleCommand *cmd)
{
	if (cmd.pipefd[0] == 1 && cmd->pipefd[1] == 0)
	{
		close(cmd->in_fd);
		dup2(cmd->out_fd, STDOUT_FILENO);
	}
	else if (cmd.pipefd[1] == 1 && cmd.pipefd[0] == 0)
	{

	}
	else
	{
	
	}
}
*/
