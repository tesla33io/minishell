/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:52:46 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/18 15:56:03 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"
#include "../../include/minishell.h"

#include <stdbool.h>
#include <stdio.h>

static t_leaf	*get_pipe_cmd(t_leaf *pl_root, int i);
static int		count_pipe_elements(t_leaf *node);

t_pipeline	*extract_pipeline(t_leaf *pl_root, t_shell_data *shd)
{
	t_pipeline	*pl;
	t_leaf		*cur;
	int			i;

	pl = gc_malloc(sizeof(*pl));
	if (!pl)
		return (NULL);
	pl->num_cmds = count_pipe_elements(pl_root) + 1;
	pl->commands = gc_malloc(sizeof(t_command *) * pl->num_cmds);
	if (!pl->commands)
		return (NULL);
	i = 0;
	cur = get_pipe_cmd(pl_root, i);
	while (i < pl->num_cmds && cur != NULL)
	{
		if (cur->token == STR || cur->token == IN_REDIRECT
			|| cur->token == OUT_REDIRECT || cur->token == APPEND
			|| cur->token == HEREDOC)
			pl->commands[i] = extract_command(cur, shd);
		i++;
		cur = get_pipe_cmd(pl_root, i);
	}
	return (pl);
}

static t_leaf	*get_pipe_cmd(t_leaf *pl_root, int i)
{
	int		j;

	j = 0;
	while (j < i)
	{
		if (pl_root->right && pl_root->right->token == PIPE)
			pl_root = pl_root->right;
		else if (pl_root->right && pl_root->right->token != PIPE)
			return (pl_root->right);
		j++;
	}
	return (pl_root->left);
}

static int	count_pipe_elements(t_leaf *node)
{
	if (node == NULL)
		return (0);
	if (node->token == PIPE)
	{
		return (1 + count_pipe_elements(node->left)
			+ count_pipe_elements(node->right));
	}
	else
	{
		return (count_pipe_elements(node->left)
			+ count_pipe_elements(node->right));
	}
}
