#include "../../include/minishell.h"

//TODO handle pair terminals

t_token *split_stream(t_token **token_stream)
{
        t_token *travel;
        t_token *ret;

        travel = (*token_stream);
        while (travel && travel->token && travel->token == TRASH)
                travel = travel->next;
        if (!travel)
                return (NULL);
        ret = travel;
        *token_stream = travel;
        while (travel && travel->next && travel->next->token != TRASH)
                travel = travel->next;
        *token_stream = travel;
        while (*token_stream && (*token_stream)->token == TRASH)
                (*token_stream) = (*token_stream)->next;
        travel->next = NULL;
        return (ret);
}

char *match_alternative(t_lex *lexer, t_token *token_stream, char **alternatives) //alternative is null at first, wont change in case of no match
{
	char *tmp;
	char *symbol; //the non-terminals and terminals within an alternative are called symbols, basically it is an umbrella term for terminals and non-terminals
	t_token *travel;

	if ((count_words(alternatives[1], ' ') > count_tokens(token_stream)) || (!contains_non_terminal(alternatives[1]) && count_words(alternatives[1], ' ') < count_tokens(token_stream)))
		return (alternatives[0]);
	tmp = ft_strdup(alternatives[1]);
	while (contains_c(tmp, ' '))
	{
		symbol = ft_chop(tmp, ' ');
		travel = token_stream;
		while (travel && contains_terminal(symbol)) 
		{
			if (travel->token == tok2int(symbol) && !travel->matched && ++travel->matched && lexer->unmatched--)
				break ;
			travel = travel->next;
		}	
		if (!travel && contains_terminal(symbol))
			return (alternatives[0]);
	}
	//if (travel && (travel->token == tok2int(symbol) || !contains_terminal(alternatives[1])))
	return (alternatives[1]);
	//else
	//	return (alternatives[0]);
}

//input for token stream is head of lexer, parent input is null at first
void ft_parse(t_shell_data *shell_data, char *production, t_leaf **parent, t_token *token_stream)
{
    char *alternative;
    char *symbol;

    printf("production selected: %s\n", production);
    alternative = NULL;
    if (!token_stream && !production && !shell_data->lexer->unmatched)
        return;

    while (contains_c(production, '|'))
        alternative = match_alternative(shell_data->lexer, token_stream, (char *[]){alternative, ft_chop(production, '|')});

    printf("alternative selected: %s\n", alternative);
    if (!alternative)
    {
        if (*parent == shell_data->ast->root)
            printf("Syntax Error\n");
        else
            printf("Syntax Error near token %s\n", token_stream->lexeme);
        return;
    }

    *parent = terminal_to_leaf(shell_data->ast, *parent, token_stream);
    while (contains_c(alternative, ' '))
    {
        symbol = ft_chop(alternative, ' ');
        if (contains_non_terminal(symbol))
            return (ft_parse(shell_data, get_production(symbol), parent, split_stream(&token_stream)));
    }
}
