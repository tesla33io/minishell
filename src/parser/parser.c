#include "minishell.h"

//TODO handle pair terminals
//split up/shorten ft 

char *match_alternative(t_lex *lexer, t_token *token_stream, char **alternatives, int *non_terminals) //alternative is null at first, wont change in case of no match
{
	printf("production rn: %s\n", production);
	char *tmp;
	char *symbol; //the non-terminals and terminals within an alternative are called symbols, basically it is an umbrella term for terminals and non-terminals
	t_token *travel;

	tmp = ft_strdup(production);
	while (contains_c(tmp, ' ')) //how will this be fucked with pair terminals?
	{
		symbol = ft_chop(tmp, ' ');
		if (contains_non_terminal(symbol))
			(*non_terminals)++; 
		else if (contains_terminal(symbol)) 
		{
			travel = lexer->head;
			while (travel)
			{
				if (travel->token == tok2int(symbol) && ++travel->matched)
					break ;
				travel = travel->next;
			}
			if (travel && travel->token != tok2int(symbol))
				return (alternative);
		}	
	}//TODO wrong if statement logic
	if ((*non_terminals > lexer->unmatched) && (!contains_terminal(production) || travel->token == tok2int(symbol)))
		return (production);
	else
		return (alternative);
}

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
	while (travel && travel->next->token != TRASH)
		travel = travel->next;
	*token_stream = travel;
	while (*token_stream && (*token_stream)->token == TRASH)
		(*token_stream) = (*token_stream)->next;
	travel->next = NULL;
	return (ret);
}

//input for token stream is head of lexer, parent input is null at first
void	ft_parse(t_shell_data *shell_data, char *production, t_leaf *parent, t_token *token_stream)
{
	char *alternative;	//within a production rule, when theres multiple possibilities that are valid for a production rule, they are called alternatives
	int non_terminals;
	char *symbol;

	alternative = NULL;
	non_terminals = 0;
	if (!production) //condition to end recursion
		return ;
	while (contains_c(production, '|')) // keep launching match on next part of grammar
		alternative = match_alternative(shell_data->lexer, t_token *token_stream, (char *[]){alternative, ft_chop(production, '|')}, &non_terminals);

 //return valid alternative TODO segfaults TODO problem: non-terminals never get reset
	if (!alternative) 
	{
		if (parent == shell_data->ast->root)
			printf("Syntax Error\n"); 
		else
			printf("Syntax Error near token %s\n", token_stream->lexeme);
	}
	parent = terminal_to_leaf(shell_data->ast, parent, token_stream);
	while (non_terminals-- && contains_c(alternative, ' '))
	{
		symbol = ft_chop(alternative, ' ');
		if (contains_non_terminal(symbol))
			return (ft_parse(shell_data, capitalize(symbol), parent, split_stream(&token_stream)));
	}
}
