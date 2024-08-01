/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adapter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 18:20:01 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/01 21:44:59 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"
#include "../../include/minishell.h"
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

static int	handle_command(t_leaf *ast_root, t_shell_data *shd);

int	adapt(t_leaf *ast_root, t_shell_data *shd)
{
	t_Pipeline	*pl;
	int			exit_code;

	exit_code = 0;
	if (ast_root->token == STR || ast_root->token == OUT_REDIRECT
		|| ast_root->token == IN_REDIRECT || ast_root->token == APPEND
		|| ast_root->token == HEREDOC)
	{
		exit_code = handle_command(ast_root, shd);
	}
	else if (ast_root->token == PIPE || ast_root->token == OUT_REDIRECT
		|| ast_root->token == IN_REDIRECT || ast_root->token == APPEND
		|| ast_root->token == HEREDOC)
	{
		pl = extract_pipeline(ast_root, shd);
		if (pl)
			execute_pipeline(pl);
	}
	return (exit_code);
}

static int	handle_command(t_leaf *ast_root, t_shell_data *shd)
{
	t_Command	*cmd;
	pid_t		cmd_pid;
	int			exit_code;

	exit_code = 0;
	cmd_pid = fork();
	cmd = NULL;
	if (cmd_pid == 0)
	{
		cmd = extract_command(ast_root, shd);
		if (!cmd)
			return (0);
		cmd->envpv = shd->envpv;
		execute_command_in_child(cmd,
				(int [2][2]){{-1, -1}, {-1, -1}}, 0, 1);
	}
	else
		waitpid(cmd_pid, &exit_code, 0);
	if (cmd && cmd->out_fd > 0)
		(close(cmd->out_fd), dup2(1, STDOUT_FILENO));
	if (cmd)
		shd->envpv = cmd->envpv;
	return (exit_code);
}
