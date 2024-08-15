/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:58:48 by ltreser           #+#    #+#             */
/*   Updated: 2024/08/15 18:11:27 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_leaf	*terminal_to_leaf(t_ast *ast, t_leaf *parent, t_token *token_stream)
{
	t_token	*travel;

	travel = token_stream;
	while (travel)
	{
		if (travel->matched)
		{
			if (!parent->terminal)
				parent = append_leaf(ast->root, parent, travel);
			else if (!parent->left->terminal)
				parent = append_leaf(parent->left, parent, travel);
			else if (!parent->right->terminal)
				parent = append_leaf(parent->right, parent, travel);
		}
		travel = travel->next;
	}
	return (parent);
}

t_leaf	*append_leaf(t_leaf *leaf, t_leaf *parent, t_token *tok)
{
	leaf->token = tok->token;
	leaf->terminal = tok->lexeme;
	leaf->var = tok->var;
	leaf->glob = tok->glob;
	leaf->parent = parent;
	leaf->left = gc_malloc(sizeof(t_leaf));
	leaf->left->terminal = NULL;
	leaf->right = gc_malloc(sizeof(t_leaf));
	leaf->right->terminal = NULL;
	tok->token = TRASH;
	return (leaf);
}

char	*get_production(char *production)
{
	int	i;

	i = 0;
	while (production[i])
		i++;
	if (!ft_strncmp(production, "complete_command", i))
		return (ft_strdup(COMPLETE_COMMAND));
	else if (!ft_strncmp(production, "pipe_sequence", i))
		return (ft_strdup(PIPE_SEQUENCE));
	else if (!ft_strncmp(production, "command", i))
		return (ft_strdup(COMMAND));
	else if (!ft_strncmp(production, "simple_command", i))
		return (ft_strdup(SIMPLE_COMMAND));
	else
		return (NULL);
}

int	count_words(char *s, char c)
{
	int	words;
	int	in_word;

	words = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == c)
			in_word = 0;
		else if (!in_word)
		{
			words++;
			in_word = 1;
		}
		s++;
	}
	return (words);
}

int	count_tokens(t_token *head)
{
	t_token	*travel;
	int		count;

	travel = head;
	count = 0;
	while (travel && ++count)
		travel = travel->next;
	return (count);
}
