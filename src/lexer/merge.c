#include "minishell.h"


// find doubles of <, >, |, & and group them as &&, ||, <<, >>
void	group_tokens(t_lex *lexer)
{
	int i;
	t_token *travel;

	i = 1; //only loop until the one before the last one, so 2 token could follow each other
	travel = lexer->head;
	while (i < lexer->tkn_count)
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
			take_out_trash(lexer);
		}
		travel = travel->next;
		i++;
	}
}

// optimizing tokenstream for parser
void	merge_tokens(t_lex *lexer)
{
	group_tokens(lexer);
	//insert_placeholder(lexer);
	//merge_strings(lexer);
	//del_empty(lexer);
}
	
