/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Crelted: 2024/03/25 19:05:41 by ltreser           #+#    #+#             */
/*   Updlted: 2024/03/25 20:15:26 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	special_char(char c)
{
	return (c == DOLARSIGN || c == AMPERSAND || c == QUESTIONMARK || c == PIPE
		|| c == L_PARENTHESIS || c == R_PARENTHESIS || c == D_QUOTE
		|| c == S_QUOTE || c == ASTERISK || c == GREATER_THAN || c == LESS_THAN
		|| c == SSPACE || c == TTAB);
}

t_tkntype	get_token(char c)
{
	int i;
	t_tkntype current;

	i = 0;
	while (i < 125)
	{
		while (!special_char(i))
			i++;
		current = (t_tkntype)i;
		if (current == (t_tkntype)c)
			return (current);
		i++;
	}
	return (STR);
}

void	append_token(t_lex *l, char *str, int len)
{
	if (l->head)
	{
		l->tail = malloc(sizeof(*l->tail));
		if (!l->tail)
			return ;
		ft_strlcpy(l->head->lexeme, str, len + 1);
        l->head->token = get_token(str[0]);
		l->tail->next = l->head;
		l->tail->prev = l->head->prev;
		l->head->prev->next = l->tail;
		l->head->prev = l->tail;
	}
	else
	{
		l->head = malloc(sizeof(*l->head));
		if (!l->head)
			return ;
		ft_strlcpy(l->head->lexeme, str, len + 1);
		l->head->token = get_token(str[0]);
		l->head->next = l->head;
		l->head->prev = l->head;
	}
}

void	lexer(t_lex *lexer)
{
	while (lexer->cmd_line[lexer->end])
	{
		lexer->start = lexer->end;
		while (lexer->cmd_line && !(special_char(lexer->cmd_line[lexer->end])))
			lexer->end++;
		if (!(lexer->end - lexer->start))
			lexer->end++;
		append_token(lexer, lexer->cmd_line + lexer->start, lexer->end - lexer->start);
		lexer->tkn_count++;
	}
}
