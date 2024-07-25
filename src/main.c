/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:28:07 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/01 22:54:14 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <signal.h>

int	main(int ac, char *av[], char *envp[])
{
	t_shell_data	*shell_data;

	(void)ac;
	(void)av;
	signal(SIGINT, sh_sigint_handler);
	gc_set_storage(5);
	shell_data = gc_malloc(sizeof(t_shell_data));
	shell_data->envpv = ft_strarray_alloc(ft_strarray_len(envp));
	if (ft_strarray_dup(envp, shell_data->envpv) < 0)
		return (dprintf(2, "minishell: fatal error: can't duplicate env"));
	while (1)
	{
		init(shell_data);
		if (render_prompt(shell_data) != -1)
		{
			lexer(shell_data->lexer);
			ft_parse(shell_data, ft_strdup(COMPLETE_COMMAND),
				shell_data->ast->root, shell_data->lexer->head);
			adapt(shell_data->ast->root, shell_data);
		}
		gc_free_gc(0);
	}
	return (0);
}

void	print_ast_leafs(t_leaf *l, int i)
{
	printf("=== LEAF [%d] (%p) ===\n", i++, (void *) l);
	printf("[%d] TERM: %s\n", l->token, l->terminal);
	printf("Parent: %p\nLeft: %p\nRight: %p\n",
		(void *) l->parent, (void *) l->left, (void *) l->right);
	if (l->left && l->left->terminal)
	{
		printf("=== =================== ===\n");
		printf("LEFT NODE of %i (%p)\n", i - 1, (void *) l);
		print_ast_leafs(l->left, i);
	}
	if (l->right && l->right->terminal)
	{
		printf("=== =================== ===\n");
		printf("RIGHT NODE of %i (%p)\n", i - 1, (void *) l);
		print_ast_leafs(l->right, i);
	}
	printf("=== =================== ===\n");
}
