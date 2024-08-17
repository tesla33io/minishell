/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adapter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 18:20:01 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/17 19:30:06 by astavrop         ###   ########.fr       */
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

void	adapt(t_leaf *ar, t_shell_data *shd)
{
	t_pipeline	*pl;

	if (is_single_cmd(ar) || is_parenthesis(ar) == 1)
		set_last_exit_code(handle_command(ar, shd), 's');
	else if (ar->token == PIPE || is_parenthesis(ar) == 2)
	{
		pl = extract_pipeline(ar, shd);
		if (pl)
			execute_pipeline(pl);
	}
	else if (ar->token == AND || is_parenthesis(ar) == 3)
	{
		adapt(ar->left, shd);
		if (set_last_exit_code(0, 'g') == 0)
			adapt(ar->right, shd);
	}
	else if (ar->token == OR || is_parenthesis(ar) == 4)
	{
		adapt(ar->left, shd);
		if (set_last_exit_code(0, 'g') != 0)
			adapt(ar->right, shd);
	}
}

static int	handle_command(t_leaf *ast_root, t_shell_data *shd)
{
	t_command	*cmd;
	pid_t		cmd_pid;
	int			exit_code;

	exit_code = 1;
	cmd = extract_command(ast_root, shd);
	if (!cmd)
		return (1);
	cmd->envpv = shd->envpv;
	if (is_builtin(cmd->bin_name))
	{
		setup_ipc(cmd, 0, (int [2][2]){{-1}}, 1);
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
