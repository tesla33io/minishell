/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adapter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 18:20:01 by astavrop          #+#    #+#             */
/*   Updated: 2024/07/23 20:18:05 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"
#include "../../include/minishell.h"
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>

int	adapt(t_leaf *ast_root, t_shell_data *shd)
{
	t_Command	*cmd;
	int			exit_code;
	pid_t		cmd_pid;

	exit_code = 0;
	if (ast_root->token == STR || ast_root->token == OUT_REDIRECT
			|| ast_root->token == IN_REDIRECT)
	{
		cmd = extract_command(ast_root);
		cmd->envpv = shd->envpv;
		if (is_builtin(cmd->bin_name))
			run_builtin(cmd);
		else
		{
			cmd_pid = fork();
			if (cmd_pid == 0)
				execute_command_in_child(cmd, (int [2][2]){{-1, -1}, {-1, -1}}, 0, 1);
			else
				waitpid(cmd_pid, &exit_code, 0);
		}
		shd->envpv = cmd->envpv;
	}
	return (exit_code);
}
