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
	return (c == AMPERSAND || c == PIPE
		|| c == L_PARENTHESIS || c == R_PARENTHESIS || c == D_QUOTE
		|| c == S_QUOTE || c == ASTERISK || c == OUT_REDIRECT || c == IN_REDIRECT
		|| c == SSPACE || c == TTAB || c == NNEWLINE);
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

void	append_token(t_lex *lexer, char *str, int len, int backslash)
{
	len = len - backslash;
	if (lexer->head)
	{
		lexer->tail = malloc(sizeof(*lexer->tail));
		if (!lexer->tail)
			return ;
		lexer->tail->lexeme = malloc((len + 1) * sizeof(char));
		ft_strlcpy(lexer->tail->lexeme, str + backslash, len + 1);
        lexer->tail->token = get_token(str[0]);
		lexer->tail->next = lexer->head;
		lexer->tail->prev = lexer->head->prev;
		lexer->head->prev->next = lexer->tail;
		lexer->head->prev = lexer->tail;
	}
	else
	{
		lexer->head = malloc(sizeof(*lexer->head)); 
		if (!lexer->head)
			return ;
		lexer->head->lexeme = malloc((len + 1) * sizeof(char));
		ft_strlcpy(lexer->head->lexeme, str + backslash, len + 1);
		lexer->head->token = get_token(str[0]);
		lexer->head->next = lexer->head;
		lexer->head->prev = lexer->head;
	}
}

void	print_tokens(t_lex *lexer)
{
	const char* token_names[] = {"x", "x", "x", "x", "x", "x", "x", "x", "NNEWLINE", "TTAB", "x", "STR", "HEREDOC", "APPEND", "AND", "OR",
	[AMPERSAND] = "AMPERSAND",
	[PIPE] = "PIPE",
	[L_PARENTHESIS] = "L_PARENTHESIS",
	[R_PARENTHESIS] = "R_PARENTHESIS",
	[D_QUOTE] = "D_QUOTE",
	[S_QUOTE] = "S_QUOTE",
	[ASTERISK] = "ASTERISK",
	[OUT_REDIRECT] = "OUT_REDIRECT",
	[IN_REDIRECT] = "IN_REDIRECT",
	[SSPACE] = "SSPACE",
};
	int i;
        t_token *travel;

        i = 0;
    	travel = lexer->head;
        while (i < lexer->tkn_count)
        {
                printf("token %d = %s : %s\n", i, token_names[travel->token], travel->lexeme);
                travel = travel->next;
                i++;
        }
}

void	lexer(t_lex *lexer)
{
	int backslash;

	while (lexer->cmd_line[lexer->end])
	{
		backslash = 0;
		lexer->start = lexer->end;
		while (lexer->cmd_line[lexer->end] && !(special_char(lexer->cmd_line[lexer->end])))
			lexer->end++;
		if (lexer->end && lexer->cmd_line[lexer->end - 1] == '\\' && ++backslash)
			lexer->end++;
		if (!(lexer->end - lexer->start))
			lexer->end++;
		append_token(lexer, (lexer->cmd_line + lexer->start), (lexer->end - lexer->start), backslash);
		lexer->tkn_count++;
	}
	print_tokens(lexer);
}
