/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:05:41 by ltreser           #+#    #+#             */
/*   Updated: 2024/08/01 23:10:11 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//see if any character is a one character token
int	special_char(char c)
{
	return (c == AMPERSAND || c == PIPE
		|| c == L_PARENTHESIS || c == R_PARENTHESIS || c == D_QUOTE
		|| c == S_QUOTE || c == OUT_REDIRECT || c == IN_REDIRECT
		|| c == SSPACE || c == TTAB || c == NNEWLINE);
}

//by looping through the range of characters of tokens (the token with the
//highest ascii value is 124, which is the PIPE token), if a number is a
//special character (one of the token special characters as above and in enum
//struct) and also the character that were trying to find the token for, we
//have successfully matched the token with the character. for matching the
//token to a lexeme, it is only necessary to pass the first character
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

//fill in the token data with lexeme and token
void	get_token_data(t_token *tok, char *str, int len, int backslash)
{
	tok->lexeme = gc_malloc((len + 1) * sizeof(char));
	if (!tok->lexeme)
		return ; //TODO error message
	ft_strlcpy(tok->lexeme, str + backslash, len + 1);
	tok->token = get_token(str[0]);
	tok->matched = 0;
	if (tok->token == L_PARENTHESIS || tok->token == R_PARENTHESIS)
		tok->pair_token = 1;
	else
		tok->pair_token = 0;
}

//add a token to the tokenstream, for now singly linked, maybe double link
//later | TODO refactor
void	append_token(t_lex *lexer, char *str, int len, int backslash)
{
	t_token	*travel;

	if (backslash && (*str + 1 == '$' || *str + 1 == '\\' || *str + 1 == '"'))
		len = len - backslash;
	else
		backslash = 0;
	if (lexer->head)
	{
		lexer->tail = gc_malloc(sizeof(*lexer->tail));
		if (!lexer->tail)
			return ;//TODO error message
		travel = lexer->head;
		while (travel->next)
			travel = travel->next;
		travel->next = lexer->tail;
		lexer->tail->next = NULL;
		get_token_data(lexer->tail, str, len, backslash);
	}
	else
	{
		lexer->head = gc_malloc(sizeof(*lexer->head));
		if (!lexer->head)
			return ; //TODO error message
		lexer->head->next = NULL;
		get_token_data(lexer->head, str, len, backslash);
	}
}

//pretty token printer
// void	print_tokens(t_lex *lexer)
// {
// 	int	i;
// 
// 	i = 0;
// 	const char* token_names[] = {"x", "x", "x", "x", "x", "x", "x", "x",
// 		"NNEWLINE", "TTAB", "x", "STR", "HEREDOC", "APPEND", "AND", "OR",
// 		"TRASH", [AMPERSAND] = "AMPERSAND", [PIPE] = "PIPE",
// 		[L_PARENTHESIS] = "L_PARENTHESIS",
// 		[R_PARENTHESIS] = "R_PARENTHESIS",
// 		[D_QUOTE] = "D_QUOTE",
// 		[S_QUOTE] = "S_QUOTE",
// 		[OUT_REDIRECT] = "OUT_REDIRECT",
// 		[IN_REDIRECT] = "IN_REDIRECT",
// 		[SSPACE] = "SSPACE",
// 	};
// 	t_token *travel;
// 
// 	travel = lexer->head;
// 	while (travel)
// 	{
// 		printf("token %d = %s : %s\n", i, token_names[travel->token],
// 		travel->lexeme);
// 		travel = travel->next;
// 		i++;
// 	}
// }

//loop through input and tokenize into initial tokens
void	lexer(t_lex *lexer)
{
	int	backslash;

	if (lexer->cmd_line[0] == 0)
		return ;
	while (lexer->cmd_line[lexer->end])
	{
		backslash = 0;
		lexer->start = lexer->end;
		while (lexer->cmd_line[lexer->end]
			&& !special_char(lexer->cmd_line[lexer->end]))
			lexer->end++;
		if (lexer->end == lexer->start && (lexer->cmd_line[lexer->end] == '"'
				|| lexer->cmd_line[lexer->end] == '\''))
			lexer->end += find_match(lexer->cmd_line + lexer->start, lexer->cmd_line[lexer->end]) + 1;
		if (lexer->end && lexer->cmd_line[lexer->end - 1] == '\\'
				&& ++backslash)
			lexer->end++;
		if (!(lexer->end - lexer->start))
			lexer->end++;
		append_token(lexer, (lexer->cmd_line + lexer->start), (lexer->end - lexer->start), backslash);
		lexer->tkn_count++;
	}
	merge_tokens(lexer);
	lexer->unmatched = lexer->tkn_count++;
}
