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

void	merge_strings(t_lex *lexer)
{
	t_token *travel;

	travel = lexer->head;
	while (travel)
	{
		if (travel->token == D_QUOTE || travel->token == S_QUOTE)
			travel->token = STR;
		if (travel->token == STR && travel->next)
		{
			if (travel->next->token == STR || travel->next->token == D_QUOTE || travel->next->token == S_QUOTE)
			{
				travel->lexeme = ft_strjoin(travel->lexeme, travel->next->lexeme);
				travel->next->token = TRASH;
				take_out_trash(lexer->head);
			}
		}
		travel = travel->next;
	}
}



// optimizing tokenstream for parser
void	merge_tokens(t_lex *lexer)
{
	group_tokens(lexer);
	//insert_placeholder(lexer);
	merge_strings(lexer);
}
	
