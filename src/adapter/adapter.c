/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adapter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 18:20:01 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/02 18:59:24 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"
#include "../../include/minishell.h"
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

static int	handle_command(t_leaf *ast_root, t_shell_data *shd);

void	adapt(t_leaf *ast_root, t_shell_data *shd)
{
	t_Pipeline	*pl;

	if (ast_root->token == STR || ast_root->token == OUT_REDIRECT
		|| ast_root->token == IN_REDIRECT || ast_root->token == APPEND
		|| ast_root->token == HEREDOC)
	{
		set_last_exit_code(handle_command(ast_root, shd), 's');
	}
	else if (ast_root->token == PIPE)
	{
		pl = extract_pipeline(ast_root, shd);
		if (pl)
			execute_pipeline(pl);
	}
	else if (ast_root->token == AND)
	{
		adapt(ast_root->left, shd);
		if (set_last_exit_code(0, 'g') == 0)
			adapt(ast_root->right, shd);
	}
	else if (ast_root->token == OR)
	{
		adapt(ast_root->left, shd);
		if (set_last_exit_code(0, 'g') != 0)
			adapt(ast_root->right, shd);
	}
}

static int	handle_command(t_leaf *ast_root, t_shell_data *shd)
{
	t_Command	*cmd;
	pid_t		cmd_pid;
	int			exit_code;

	exit_code = 1;
	cmd_pid = fork();
	cmd = NULL;
	if (cmd_pid == 0)
	{
		cmd = extract_command(ast_root, shd);
		if (!cmd)
			return (1);
		cmd->envpv = shd->envpv;
		execute_command_in_child(cmd,
				(int [2][2]){{-1, -1}, {-1, -1}}, 0, 1);
	}
	else
		exit_code = get_exit_code(cmd_pid);
	if (cmd && cmd->out_fd > 0)
		(close(cmd->out_fd), dup2(1, STDOUT_FILENO));
	if (cmd)
		shd->envpv = cmd->envpv;
	return (exit_code);
}
