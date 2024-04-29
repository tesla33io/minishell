/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:59:25 by astavrop          #+#    #+#             */
/*   Updated: 2024/04/29 21:14:07 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> /* pid_t, fork */

#include "../../include/executor.h"
#include "../../lib/libft/libft.h"

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
	if (is_builtint(cmd->bin, (char *[]){"echo", "cd", "pwd", "export", "unset",
				"env", "exit", NULL}))
	{
		// run builtin
	}
	else if (ft_strncmp(cmd->bin, "./", 2) == 0)
	{
		// run local bin
	}
	else
	{
		// run bin on $PATH
	}
	return (-1);
}

/*
 * executes a command and
 * returns an id of child process
 */
int	execute_command(t_SimpleCommand *cmd)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		fork_fail();
	if (pid == 0)
	{
		// check and look for binary
		close(cmd->in_fd);
		dup2(cmd->out_fd, STDOUT_FILENO);
		if (execve(cmd->bin, cmd->args, cmd->envp) < 0)
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
