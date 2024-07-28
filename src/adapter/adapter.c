/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adapter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 18:20:01 by astavrop          #+#    #+#             */
/*   Updated: 2024/07/28 18:46:10 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"
#include "../../include/minishell.h"
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>

static int	handle_command(t_leaf *ast_root, t_shell_data *shd);

int	adapt(t_leaf *ast_root, t_shell_data *shd)
{
	t_Command	*cmd;
	t_Pipeline	*pl;
	int			exit_code;
	pid_t		cmd_pid;

	exit_code = 0;
	if (ast_root->token == STR || ast_root->token == OUT_REDIRECT
		|| ast_root->token == IN_REDIRECT)
	{
		exit_code = handle_command(ast_root, shd);
	}
	else if (ast_root->token == PIPE || ast_root->token == OUT_REDIRECT
		|| ast_root->token == IN_REDIRECT)
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
	cmd = extract_command(ast_root, shd);
	cmd->envpv = shd->envpv;
	if (is_builtin(cmd->bin_name))
		run_builtin(cmd);
	else
	{
		cmd_pid = fork();
		if (cmd_pid == 0)
		{
			execute_command_in_child(cmd,
				(int [2][2]){{-1, -1}, {-1, -1}}, 0, 1);
		}
		else
			waitpid(cmd_pid, &exit_code, 0);
	}
	shd->envpv = cmd->envpv;
	return (exit_code);
}
