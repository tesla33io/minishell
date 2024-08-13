/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adapter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 18:20:01 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/12 21:23:15 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"
#include "../../include/minishell.h"
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

static int	handle_command(t_leaf *ast_root, t_shell_data *shd);
static void	print_if_signal(int exit_code);

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
	cmd = extract_command(ast_root, shd);
	if (!cmd)
		return (1);
	cmd->envpv = shd->envpv;
	if (is_builtin(cmd->bin_name))
	{
		setup_ipc(cmd, 0, (int [2][2]) {{-1}}, 1);
		exit_code = run_builtin(cmd);
	}
	else
	{
		cmd_pid = fork();
		if (cmd_pid == 0)
			execute_command_in_child(cmd, (int [2][2]){{-1}}, 0, 1);
		else
			exit_code = get_exit_code(cmd_pid);
	}
	print_if_signal(exit_code);
	shd->envpv = cmd->envpv;
	return (exit_code);
}

static void	print_if_signal(int exit_code)
{
	if (exit_code == SIGSEGV)
		ft_putendl_fd("Oops! Segmentation fault (don't panic!)", 2);
	else if (exit_code == SIGQUIT)
		ft_putendl_fd("Oops! Quit (core ! dumped)", 2);
	else if (exit_code == SIGILL)
		ft_putendl_fd("Oops! Illegal instuction (don't you dare!)", 2);
	else if (exit_code == SIGABRT)
		ft_putendl_fd("Oops! Aborted (core ! dumped)", 2);
	else if (exit_code == SIGTERM)
	{
		ft_putendl_fd("Oops! Terminated (Your clothes. Give them to me. Now)",
			2);
	}
	else if (exit_code == SIGKILL)
		ft_putendl_fd("Oops! Killed (I'm calling the cops!)", 2);
}
