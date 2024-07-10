/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:28:07 by astavrop          #+#    #+#             */
/*   Updated: 2024/07/10 21:07:58 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(void)
{
	t_shell_data *shell_data;
	static int	i = 0;

	shell_data = malloc(sizeof(t_shell_data));
	while (1)
	{
		init(shell_data);
		if (render_prompt(shell_data))
		{
			lexer(shell_data->lexer);
			printf("lexer done\n___________\n\n");
			ft_parse(shell_data, ft_strdup(COMPLETE_COMMAND), shell_data->ast->root, shell_data->lexer->head); 
			printf("\n\033[33;3m*** *** *** Parsing DONE! *** *** ***\033[0m\n\n");
			i = 0;
			print_ast_leafs(shell_data->ast->root, i);
		}
			//GC CLEAN
	}
	return (0);
}

void	print_ast_leafs(t_leaf *l, int i)
{
	printf("=== LEAF [%d] (%p) ===\n", i++, (void *) l);
	printf("[%d] TERM: %s\n", l->token, l->terminal);
	printf("Parent: %p\nLeft: %p\nRight: %p\n",
			(void *) l->parent, (void *) l->left, (void *) l->right);
	if (l->left->terminal)
	{
		printf("=== ======================\n");
		printf("LEFT NODE of %i (%p)\n", i - 1, (void *) l);
		print_ast_leafs(l->left, i);
	}
	if (l->right->terminal)
	{
		printf("=== ======================\n");
		printf("RIGHT NODE of %i (%p)\n", i - 1, (void *) l);
		print_ast_leafs(l->right, i);
	}
}

//init unmatched and matched in lexer and token
