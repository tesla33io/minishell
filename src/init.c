/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 23:14:35 by ltreser           #+#    #+#             */
/*   Updated: 2024/08/06 18:28:12 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

#include <unistd.h>

void	init_lexer(t_shell_data *shell_data)
{
	shell_data->lexer = gc_malloc(sizeof(t_lex));
	shell_data->lexer->head = NULL;
	shell_data->lexer->tail = NULL;
	shell_data->lexer->start = 0;
	shell_data->lexer->end = 0;
	shell_data->lexer->tkn_count = 0;
}

void	init(t_shell_data *shell_data)
{
	gc_set_storage(5);
	init_lexer(shell_data);
	shell_data->ast = gc_malloc(sizeof(t_ast));
	shell_data->ast->leafcount = 0;
	shell_data->ast->root = gc_malloc(sizeof(t_leaf));
	shell_data->ast->root->terminal = NULL;
	shell_data->parse_fail = 0;
	gc_set_storage(0);
}
