/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:52:46 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/01 22:54:14 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"
#include "../../include/minishell.h"

#include <stdbool.h>
#include <stdio.h>

/*#define PRINT_LEAF(node) do { \
    if (node == NULL) { \
		printf("------------"); \
        printf("Node is NULL\n"); \
    } else { \
		printf(">>>>>>>>>>>>>>>>>>>>>\n"); \
        printf("Token: %d\n", (node)->token); \
        printf("Terminal: %s\n", (node)->terminal ? \
        (node)->terminal : "NULL"); \
        printf("Parent: %p\n", (void*)(node)->parent); \
		if ((node)->parent) { \
			printf("\tToken: %d\n", (node)->parent->token); \
			printf("\tTerminal: %s\n", (node)->parent->terminal); \
			printf("\tLeft: %s\n", (node)->parent->left->terminal); \
			printf("\tRight: %s\n", (node)->parent->right->terminal); \
		} \
        printf("Left: %p\n", (void*)(node)->left); \
        printf("Right: %p\n", (void*)(node)->right); \
    } \
} while (0) */

static t_leaf	*get_pipe_cmd(t_leaf *pl_root, int i);
static int		count_pipe_elements(t_leaf *node);

t_Pipeline	*extract_pipeline(t_leaf *pl_root, t_shell_data *shd)
{
	t_Pipeline	*pl;
	t_leaf		*cur;
	int			i;

	pl = gc_malloc(sizeof(*pl));
	if (!pl)
		return (NULL);
	pl->num_cmds = count_pipe_elements(pl_root) + 1;
	pl->commands = gc_malloc(sizeof(t_Command *) * pl->num_cmds);
	if (!pl->commands)
		return (NULL);
	i = 0;
	while (i < pl->num_cmds && cur != NULL)
	{
		cur = get_pipe_cmd(pl_root, i);
		if (cur->token == STR || cur->token == IN_REDIRECT
			|| cur->token == OUT_REDIRECT || cur->token == APPEND
			|| cur->token == HEREDOC)
			pl->commands[i] = extract_command(cur, shd);
		i++;
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
