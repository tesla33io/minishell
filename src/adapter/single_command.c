/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:00:07 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/17 20:09:38 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"
#include "../../include/minishell.h"

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

static t_command	*init_command(t_shell_data *shd);

t_command	*extract_command(t_leaf *cmd_root, t_shell_data *shd)
{
	t_command	*cmd;
	t_leaf		*next;

	cmd = init_command(shd);
	cmd->args = ft_strarray_alloc(0);
	if (!cmd)
		return (NULL);
	next = handle_first_redir(cmd_root, cmd);
	if (!next)
		return (NULL);
	if (next && next->token == 0)
		return (NULL);
	extract_args(next, cmd);
	if (cmd->in_fd < 0 || cmd->out_fd < 0)
		return (NULL);
	cmd->bin_name = cmd->args[0];
	return (cmd);
}

/* Helper functions */
static t_command	*init_command(t_shell_data *shd)
{
	t_command	*cmd;

	(void)shd;
	cmd = gc_malloc(sizeof(*cmd));
	if (!cmd)
		return (NULL);
	cmd->bin_name = NULL;
	cmd->args = ft_strarray_alloc(0);
	cmd->envpv = shd->envpv;
	cmd->in_fd = 0;
	cmd->out_fd = 1;
	cmd->append = false;
	cmd->heredoc = false;
	return (cmd);
}

int	handle_out_redirect(t_leaf **n, t_command *c)
{
	bool	append;

	append = false;
	if ((*n)->token == APPEND)
		append = true;
	*n = (*n)->left;
	if (!append)
		c->out_fd = open((*n)->terminal, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else if (append)
		c->out_fd = open((*n)->terminal, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (c->out_fd == -1)
	{
		perror((*n)->terminal);
		return (2);
	}
	c->append = append;
	return (0);
}

int	handle_in_redirect(t_leaf **next, t_command *cmd)
{
	bool	heredoc;

	heredoc = false;
	if ((*next)->token == HEREDOC)
		heredoc = true;
	*next = (*next)->left;
	if (!heredoc)
		cmd->in_fd = open((*next)->terminal, O_RDONLY);
	else if (heredoc)
		cmd->in_fd = start_heredoc((*next)->terminal);
	if (cmd->in_fd == -1)
	{
		perror((*next)->terminal);
		return (2);
	}
	cmd->heredoc = heredoc;
	return (0);
}

void	extract_args(t_leaf *node, t_command *cmd)
{
	while (node)
	{
		if (node->token == STR)
		{
			if (contains_c(node->terminal, '$'))
				var_expand(node, cmd);
			cmd->args = ft_strarray_append(cmd->args, node->terminal);
		}
		else if (node->token == OUT_REDIRECT || node->token == APPEND)
		{
			if (handle_out_redirect(&node, cmd) == 2)
				break ;
		}
		else if (node->token == IN_REDIRECT || node->token == HEREDOC)
		{
			if (handle_in_redirect(&node, cmd) == 2)
				break ;
		}
		node = node->left;
	}
}
