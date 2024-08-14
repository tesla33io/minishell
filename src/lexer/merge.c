#include "../../include/minishell.h"

// find doubles of <, >, |, & and group them as &&, ||, <<, >>
void	group_tokens(t_lex *lexer)
{
	t_token	*trvl;

	trvl = lexer->head;
	while (trvl && trvl->next)
	{
		if (trvl->token == IN_REDIRECT && trvl->next->token == IN_REDIRECT)
			trvl->token = HEREDOC;
		if (trvl->token == OUT_REDIRECT && trvl->next->token == OUT_REDIRECT)
			trvl->token = APPEND;
		if (trvl->token == AMPERSAND && trvl->next->token == AMPERSAND)
			trvl->token = AND;
		if (trvl->token == PIPE && trvl->next->token == PIPE)
			trvl->token = OR;
		if (trvl->token == HEREDOC || trvl->token == APPEND
			|| trvl->token == AND || trvl->token == OR)
		{
			trvl->lexeme = ft_strjoin(trvl->lexeme, trvl->next->lexeme);
			trvl->next->token = TRASH;
			take_out_trash(lexer->head);
		}
		trvl = trvl->next;
	}
}

void	remove_quotations(char *str)
{
	int	dest;
	int	src;

	dest = 0;
	src = 0;
	if (!contains_c(str, '\'') || !contains_c(str, '"'))
		return ;
	while (str[src])
	{
		if (!((str[src] == '"' || str[src] == '\'') && (src == 0 || src == (ft_strlen(str) - 1))))
		{
			ft_memmove(str + dest, str + src, 1);
			dest++;
		}
		src++;
	}
	while (str[dest])
	{
		ft_bzero(str + dest, 1);
		dest++;
	}
}

void	merge_strings(t_lex *lexer)
{
	t_token	*travel;

	travel = lexer->head;
	while (travel)
	{
		if (travel->token == D_QUOTE || travel->token == S_QUOTE)
			travel->token = STR;
		travel = travel->next;
	}
	travel = lexer->head;
	while (travel)
	{
		while (travel && travel->next && travel->token == STR
			&& travel->next->token == STR)
		{
			remove_quotations(travel->lexeme);
			remove_quotations(travel->next->lexeme);
			travel->lexeme = ft_strjoin(travel->lexeme, travel->next->lexeme);
			travel->var = ft_strjoin(travel->var, travel->next->var);
			travel->glob = ft_strjoin(travel->glob, travel->next->glob);
			travel->next->token = TRASH;
			take_out_trash(lexer->head);
		}
		travel = travel->next;
	}
}

void	remove_spaces(t_lex *lexer)
{
	t_token	*travel;

	travel = lexer->head;
	while (travel)
	{
		if (travel->token == SSPACE)
			travel->token = TRASH;
		travel = travel->next;
	}
	take_out_trash(lexer->head);
}

// optimizing tokenstream for parser
void	merge_tokens(t_lex *lexer)
{
	group_tokens(lexer);
	set_varflag(lexer);
	set_globflag(lexer);
	merge_strings(lexer);
	remove_spaces(lexer);
}
