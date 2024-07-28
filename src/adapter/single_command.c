/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:00:07 by astavrop          #+#    #+#             */
/*   Updated: 2024/07/28 18:50:18 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"
#include "../../include/minishell.h"

#include <fcntl.h>  // for open
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
	if (next->token == OUT_REDIRECT)
	{
		if (handle_out_redirect(&next, cmd) == -1)
			return (NULL);
	}
	else if (next->token == IN_REDIRECT)
	{
		if (handle_in_redirect(&next, cmd) == -1)
			return (NULL);
	}
	if (next->token == STR)
		cmd->bin_name = next->terminal;
	extract_args(next, cmd);
	return (cmd);
}

/* Helper functions */
static t_Command	*init_command(t_shell_data *shd)
{
	t_Command	*cmd;

	cmd = gc_malloc(sizeof(*cmd));
	if (!cmd)
		return (NULL);
	cmd->bin_name = NULL;
	cmd->args = ft_strarray_alloc(0);
	cmd->envpv = NULL;
	if (shd->envpv)
		cmd->envpv = shd->envpv;
	cmd->in_fd = 0;
	cmd->out_fd = 1;
	return (cmd);
}

static int	handle_out_redirect(t_leaf **next, t_Command *cmd)
{
	*next = (*next)->left;
	cmd->out_fd = open((*next)->terminal, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (cmd->out_fd == -1)
		return (-1);
	*next = (*next)->left;
	return (0);
}

static int	handle_in_redirect(t_leaf **next, t_Command *cmd)
{
	*next = (*next)->left;
	cmd->in_fd = open((*next)->terminal, O_RDONLY);
	if (cmd->in_fd == -1)
		return (-1);
	*next = (*next)->left;
	return (0);
}

void	extract_args(t_leaf *next, t_Command *cmd)
{
	while (next)
	{
		if (next->token == STR)
			cmd->args = ft_strarray_append(cmd->args, next->terminal);
		else if (next->token == OUT_REDIRECT)
		{
			if (handle_out_redirect(&next, cmd) == -1)
				return ;
		}
		else if (next->token == IN_REDIRECT)
		{
			if (handle_in_redirect(&next, cmd) == -1)
				return ;
		}
		next = next->left;
	}
}
