/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:52:46 by astavrop          #+#    #+#             */
/*   Updated: 2024/07/27 15:38:16 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"
#include "../../include/minishell.h"

#include <stdio.h>

#define PRINT_LEAF(node) do { \
    if (node == NULL) { \
		printf("------------"); \
        printf("Node is NULL\n"); \
    } else { \
		printf(">>>>>>>>>>>>>>>>>>>>>\n"); \
        printf("Token: %d\n", (node)->token); \
        printf("Terminal: %s\n", (node)->terminal ? (node)->terminal : "NULL"); \
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
} while (0)

static t_leaf	*get_first_pipe_cmd(t_leaf *pl_root);
static int		count_pipe_elements(t_leaf *node);

t_Pipeline	*extract_pipeline(t_leaf *pl_root, t_shell_data *shd)
{
	t_Pipeline	*pl;
	t_leaf		*cur;
	int			i;

	pl = gc_malloc(sizeof(*pl));
	if (!pl)
		return (NULL);
	pl->num_cmds = count_pipe_elements(pl_root);
	pl->commands = gc_malloc(sizeof(t_Command *) * pl->num_cmds);
	if (!pl->commands)
		return (NULL);
	i = 0;
	cur = get_first_pipe_cmd(pl_root);
	while (i < pl->num_cmds && cur != NULL)
	{
		// PRINT_LEAF(cur);
		if (cur->token == STR)
			pl->commands[i++] = extract_command(cur, shd);
		if (cur->parent && cur->parent->right)
			cur = get_first_pipe_cmd(cur->parent->right);
	//	if (cur->parent && cur->parent->token == PIPE)
	//	{
	//		if (cur == cur->parent->left && cur->parent->right && cur->parent->right->token == STR)
	//			cur = cur->parent->right;
	//		else
	//			cur = cur->parent;
	//	}
	//	else
	//		break ;
	}
	return (pl);
}

static t_leaf	*get_first_pipe_cmd(t_leaf *pl_root)
{
	t_leaf	*left_most;

	left_most = pl_root;
	while (left_most && left_most->token == PIPE)
		left_most = left_most->left;
	return (left_most);
}

static int	count_pipe_elements(t_leaf *node)
{
	int	count;

	count = 0;
	if (node->token == STR)
		count = 1;
	if (node->token == PIPE)
	{
		count += count_pipe_elements(node->left);
		count += count_pipe_elements(node->right);
	}
	return (count);
}
