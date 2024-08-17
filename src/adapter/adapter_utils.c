/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adapter_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:17:09 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/17 19:25:38 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_parenthesis(t_leaf *ar)
{
	if (ar->token == L_PARENTHESIS && ar->left->token == R_PARENTHESIS)
	{
		if (ar->left->left && is_single_cmd(ar->left->left))
			return (1);
		else if (ar->left->left && ar->left->left->token == PIPE)
			return (2);
		else if (ar->left->left && ar->left->left->token == AND)
			return (3);
		else if (ar->left->left && ar->left->left->token == OR)
			return (4);
	}
	return (0);
}

int	is_single_cmd(t_leaf *node)
{
	if (node->token == STR || node->token == OUT_REDIRECT
		|| node->token == IN_REDIRECT || node->token == APPEND
		|| node->token == HEREDOC)
		return (1);
	return (0);
}
