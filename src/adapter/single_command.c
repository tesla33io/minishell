/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:00:07 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/06 17:37:05 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"
#include "../../include/minishell.h"

#include <fcntl.h>  // for open
#include <stdio.h>
#include <stdlib.h> // for NULL

/* Function prototypes */
static t_Command	*init_command(t_shell_data *shd);
static int			handle_out_redirect(t_leaf **next, t_Command *cmd);
static int			handle_in_redirect(t_leaf **next, t_Command *cmd);

/* Main function */
/* Not sure about returning NULL on redirect fail */
/* TODO: look into it later :D */
t_Command	*extract_command(t_leaf *cmd_root, t_shell_data *shd)
{
	t_Command	*cmd;
	t_leaf		*next;

	cmd = init_command(shd);
	cmd->args = ft_strarray_alloc(0);
	next = cmd_root;
	if (!cmd)
		return (NULL);
	if (next->token == OUT_REDIRECT || next->token == APPEND)
	{
		handle_out_redirect(&next, cmd);
		next = next->left;
	}
	else if (next->token == IN_REDIRECT || next->token == HEREDOC)
	{
		handle_in_redirect(&next, cmd);
		next = next->left;
	}
	if (next && next->token == 0)
		return (NULL);
	extract_args(next, cmd);
	cmd->bin_name = cmd->args[0];
	return (cmd);
}

/* Helper functions */
static t_Command	*init_command(t_shell_data *shd)
{
	t_Command	*cmd;

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

static int	handle_out_redirect(t_leaf **n, t_Command *c)
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
		c->out_fd = open("/dev/zero", O_WRONLY);
		if (c->out_fd == -1)
			exit ((perror("fatal: open"), -1));
		return (-1);
	}
	c->append = append;
	return (0);
}

static int	handle_in_redirect(t_leaf **next, t_Command *cmd)
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
		cmd->in_fd = open("/dev/null", O_RDONLY);
		if (cmd->in_fd == -1)
			exit ((perror("fatal: open"), -1));
		return (-1);
	}
	cmd->heredoc = heredoc;
	return (0);
}

void	extract_args(t_leaf *node, t_Command *cmd)
{
	while (node)
	{
		if (node->token == STR)
			cmd->args = ft_strarray_append(cmd->args, node->terminal);
		else if (node->token == OUT_REDIRECT || node->token == APPEND)
			handle_out_redirect(&node, cmd);
		else if (node->token == IN_REDIRECT || node->token == HEREDOC)
			handle_in_redirect(&node, cmd);
		node = node->left;
	}
}
