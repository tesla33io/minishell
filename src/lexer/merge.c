#include "minishell.h"


// find doubles of <, >, |, & and group them as &&, ||, <<, >>
void	group_tokens(t_lex *lexer)
{
	t_token *travel;

	travel = lexer->head;
	while (travel->next)
	{
		if (travel->token == IN_REDIRECT && travel->next->token == IN_REDIRECT)
			travel->token = HEREDOC;
		if (travel->token == OUT_REDIRECT && travel->next->token == OUT_REDIRECT)
                        travel->token = APPEND;
		if (travel->token == AMPERSAND && travel->next->token == AMPERSAND)
                        travel->token = AND;
		if (travel->token == PIPE && travel->next->token == PIPE)
                        travel->token = OR;
		if (travel->token == HEREDOC || travel->token == APPEND || travel->token == AND || travel->token == OR)
		{
			travel->lexeme = ft_strjoin(travel->lexeme, travel->next->lexeme);
			travel->next->token = TRASH;
			take_out_trash(lexer->head);
		}
		travel = travel->next;
	}
}

void	remove_quotations(char *str)
{
	// printf("token is: %s\n", str);
	int dest;
	int src;

	dest = 0;
	src = 0;
	while (str[src])
	{
		if (!(str[src] == '"' || str[src] == '\''))
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

void	merge_strings(t_lex *lexer) //needs to be fixed bc merges 2 consecutive strings max
{
	t_token *travel;

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
		while (travel && travel->next && travel->token == STR && travel->next->token == STR)
		{	
			travel->lexeme = ft_strjoin(travel->lexeme, travel->next->lexeme);
			travel->next->token = TRASH;
			take_out_trash(lexer->head);
		}
		remove_quotations(travel->lexeme);
		travel = travel->next;
	}
}

void remove_spaces(t_lex *lexer)
{
	t_token *travel;

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
	//insert_placeholder(lexer);
	merge_strings(lexer);
	remove_spaces(lexer);
}
	
