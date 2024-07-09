/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:28:07 by astavrop          #+#    #+#             */
/*   Updated: 2024/07/10 00:02:42 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(void)
{
	t_shell_data *shell_data;

	shell_data = malloc(sizeof(t_shell_data));
	while (1)
	{
		init(shell_data);
		if (render_prompt(shell_data))
		{
			lexer(shell_data->lexer);
			printf("lexer done\n___________\n\n");
			ft_parse(shell_data, ft_strdup(COMPLETE_COMMAND), shell_data->ast->root, shell_data->lexer->head); 
		}
		print_ast_leafs(shell_data->ast->root);
			//GC CLEAN
	}
	return (0);
}

void	print_ast_leafs(t_leaf *l)
{
	static int	i = 0;
	static t_leaf	*root = NULL;
	int			has_left = 1;
	int			has_right = 1;

	printf("=== LEAF [%d] (%p) ===\n", i++, (void *) l);
	printf("TERM: %s\n", l->terminal);
	printf("Parent: %p\nLeft: %p\nRight: %p\n",
			(void *) l->parent, (void *) l->left, (void *) l->right);
	if (i == 1)
		root = l->parent;
	while (1 && i == 1)
	{
		if (l->left)
			print_ast_leafs(l->left);
		else if (root->right && (has_left = 0, 1))
			print_ast_leafs(root->right);
		else
			has_right = 0;

		if (!has_left && !has_right)
			break ;
	}
}

//init unmatched and matched in lexer and token
