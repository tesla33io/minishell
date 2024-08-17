/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:05:41 by ltreser           #+#    #+#             */
/*   Updated: 2024/08/17 17:53:20 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// see if any character is a one character token
int	special_char(char c)
{
	return (c == AMPERSAND || c == PIPE || c == L_PARENTHESIS
		|| c == R_PARENTHESIS || c == D_QUOTE || c == S_QUOTE
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
void	get_token_data(t_token *tok, char *str, int len, int backslash)
{
	tok->lexeme = gc_malloc((len + 1) * sizeof(char));
	if (!tok->lexeme)
		return ;
	tok->next = NULL;
	ft_strlcpy(tok->lexeme, str + backslash, len + 1);
	tok->token = get_token(str[0]);
	tok->matched = 0;
	tok->var = NULL;
}

void	append_token(t_lex *lexer, char *str, int len, int backslash)
{
	t_token	*travel;

	if (!len)
		return ;
	if (backslash && (*str + 1 == '$' || *str + 1 == '\\' || *str + 1 == '"'))
		len = len - backslash;
	else
		backslash = 0;
	if (lexer->head)
	{
		lexer->tail = gc_malloc(sizeof(*lexer->tail));
		if (!lexer->tail)
			return ;
		travel = lexer->head;
		while (travel->next)
			travel = travel->next;
		travel->next = lexer->tail;
		get_token_data(lexer->tail, str, len, backslash);
	}
	else
	{
		lexer->head = gc_malloc(sizeof(*lexer->head));
		if (!lexer->head)
			return ;
		get_token_data(lexer->head, str, len, backslash);
	}
}

void	lexer(t_lex *lexer)
{
	int	backslash;
	int quote;

	while (lexer->cmd_line[lexer->end])
	{
		backslash = 0;
		quote = 0;
		lexer->start = lexer->end;
		while (lexer->cmd_line[lexer->end]
			&& !special_char(lexer->cmd_line[lexer->end]))
			lexer->end++;
		if (lexer->end == lexer->start && (lexer->cmd_line[lexer->end] == '"'
				|| lexer->cmd_line[lexer->end] == '\''))
			lexer->end += find_match(lexer->cmd_line + lexer->start,
					lexer->cmd_line[lexer->end], &quote) + 1;
		if (lexer->end && lexer->cmd_line[lexer->end - 1] == '\\'
			&& ++backslash)
			lexer->end++;
		if (!(lexer->end - lexer->start))
			lexer->end++;
		append_token(lexer, (lexer->cmd_line + lexer->start + quote), (lexer->end
				- (lexer->start + (quote * 2))), backslash);
		lexer->tkn_count++;
	}
	merge_tokens(lexer);
}

