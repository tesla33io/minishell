/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adapter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 18:20:01 by astavrop          #+#    #+#             */
/*   Updated: 2024/07/14 18:09:08 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"
#include "../../include/minishell.h"
#include <fcntl.h>

static t_Command	*extract_command(t_leaf *cmd_root);

int	adapt(t_leaf *ast_root)
{
	t_Command	*cmd;

	if (ast_root->token == STR || ast_root->token == OUT_REDIRECT
			|| ast_root->token == IN_REDIRECT)
	{
		cmd = extract_command(ast_root);
		// print_cmd(cmd);
		execute_command_in_child(cmd, (int [2][2]){{-1, -1}, {-1, -1}}, 0, 1);
	}
	return (0);
}

/* TODO: access check, open err handling */
static t_Command	*extract_command(t_leaf *cmd_root)
{
	t_leaf		*next;
	t_Command	*ret_cmd;

	ret_cmd = gc_malloc(sizeof(*ret_cmd));
	if (!ret_cmd)
		return (NULL);
	next = cmd_root;
	if (next->token == OUT_REDIRECT)
	{
		next = next->left;
		ret_cmd->out_fd = open(next->terminal,
				O_CREAT | O_WRONLY | O_TRUNC, 0644);
		next = next->left;
		/* TODO: what if open fails? */
	}
	else if (next->token == IN_REDIRECT)
	{
		next = next->left;
		ret_cmd->in_fd = open(next->terminal, O_RDONLY);
		next = next->left;
		/* TODO: what if open fails? */
	}
	if (next->token == STR)
		ret_cmd->bin_name = next->terminal;
	ret_cmd->args = ft_strarray_alloc(1);
	ret_cmd->envpv = NULL;
	ret_cmd->in_fd = 0;
	ret_cmd->out_fd = 1;
	while (next)
	{
		if (next->token == STR)
			ret_cmd->args = ft_strarray_append(ret_cmd->args, next->terminal);
		else if (next->token == OUT_REDIRECT)
		{
			next = next->left;
			ret_cmd->out_fd = open(next->terminal,
					O_CREAT | O_WRONLY | O_TRUNC, 0644);
			/* TODO: what if open fails? */
		}
		else if (next->token == IN_REDIRECT)
		{
			next = next->left;
			ret_cmd->in_fd = open(next->terminal, O_RDONLY);
			/* TODO: what if open fails? */
		}
		next = next->left;
	}
	return (ret_cmd);
}
