/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:05:41 by ltreser           #+#    #+#             */
/*   Updated: 2024/08/18 15:56:41 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// see if any character is a one character token
int	special_char(char c)
{
	return (c == AMPERSAND || c == PIPE || c == D_QUOTE || c == S_QUOTE
		|| c == OUT_REDIRECT || c == IN_REDIRECT || c == SSPACE || c == TTAB
		|| c == NNEWLINE);
}

// by looping through the range of characters of tokens (the token with the
// highest ascii value is 124, which is the PIPE token), if a number is a
// special character (one of the token special characters as above and in enum
// struct) and also the character that were trying to find the token for, we
// have successfully matched the token with the character. for matching the
// token to a lexeme, it is only necessary to pass the first character
t_tkntype	get_token(char c)
{
	int	i;

	i = 0;
	while (i < 125)
	{
		while (!special_char(i))
			i++;
		if ((t_tkntype)i == (t_tkntype)c)
			return ((t_tkntype)i);
		i++;
	}
	return (STR);
}

// fill in the token data with lexeme and token
void	get_token_data(t_lex *lexer, t_token *tok, char *str, int len)
{
	tok->lexeme = gc_malloc((len + 1) * sizeof(char));
	if (!tok->lexeme)
		return ;
	tok->next = NULL;
	tok->token = get_token(str[0]);
	ft_strlcpy(tok->lexeme, str + lexer->backslash + lexer->quote, len + 1 - (2
			* lexer->quote));
	tok->matched = 0;
	tok->var = NULL;
}

void	append_token(t_lex *lexer, char *str, int len)
{
	t_token	*travel;

	if (lexer->backslash && (*str + 1 == '$' || *str + 1 == '\\' || *str
			+ 1 == '"'))
		len = len - lexer->backslash;
	else
		lexer->backslash = 0;
	if (lexer->head)
	{
		lexer->tail = gc_malloc(sizeof(*lexer->tail));
		if (!lexer->tail)
			return ;
		travel = lexer->head;
		while (travel->next)
			travel = travel->next;
		travel->next = lexer->tail;
		get_token_data(lexer, lexer->tail, str, len);
	}
	else
	{
		lexer->head = gc_malloc(sizeof(*lexer->head));
		if (!lexer->head)
			return ;
		get_token_data(lexer, lexer->head, str, len);
	}
}

void	lexer(t_lex *l)
{
	while (l->cmd_line[l->end])
	{
		l->backslash = 0;
		l->quote = 0;
		l->start = l->end;
		while (l->cmd_line[l->end] && !special_char(l->cmd_line[l->end]))
			l->end++;
		if (l->end == l->start && (l->cmd_line[l->end] == '"'
				|| l->cmd_line[l->end] == '\''))
			l->end += find_match(l->cmd_line + l->start, l->cmd_line[l->end], l)
				+ 1;
		if (l->end && l->cmd_line[l->end - 1] == '\\' && ++l->backslash)
			l->end++;
		if (!(l->end - l->start))
			l->end++;
		if (l->end - l->start)
			append_token(l, (l->cmd_line + l->start), (l->end - l->start));
		l->tkn_count++;
	}
	merge_tokens(l);
}
