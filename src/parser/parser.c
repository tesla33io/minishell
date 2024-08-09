#include "../../include/minishell.h"

//TODO handle pair terminals

//return stoken stream up until trash, move pointer for token stream
t_token	*split_stream(t_token **token_stream)
{
	t_token	*travel;
	t_token	*ret;

	travel = (*token_stream);
	if (!contains_token(*(token_stream), TRASH))
		return (*(token_stream));
	while (travel && travel->token && travel->token == TRASH)
		travel = travel->next;
	if (!travel)
		return (NULL);
	(*token_stream) = travel;
	while (*token_stream && (*token_stream)->token != TRASH)
		*token_stream = (*token_stream)->next;
	while (*token_stream && (*token_stream)->token == TRASH)
		*token_stream = (*token_stream)->next;
	ret = travel;
	while (travel && travel->next && travel->next->token != TRASH)
		travel = travel->next;
	take_out_trash(*(token_stream));
	travel->next = NULL;
	return (ret);
}

//helper function to find the correct alternative of a given production rule
char	*match_alternative(t_lex *lexer, t_token *token_stream,
	char **alternatives)
{
	char	*tmp;
	char	*symbol;
	t_token	*travel;
	int		i = 0;

	if ((count_words(alternatives[1], ' ') > count_tokens(token_stream))
		|| (!contains_non_terminal(alternatives[1])
			&& count_words(alternatives[1], ' ') < count_tokens(token_stream)))
		return (alternatives[0]);
	tmp = ft_strdup(alternatives[1]);
	while (contains_c(tmp, ' '))
	{
		symbol = ft_chop(tmp, ' ');
		travel = token_stream;
		while (travel && contains_terminal(symbol))
		{
			if (travel->token == tok2int(symbol) && (i || (!i && travel == token_stream))
				&& !travel->matched
				&& ++travel->matched && lexer->unmatched--)
				break ;
			travel = travel->next;
		}
		if (!travel && contains_terminal(symbol))
			return (alternatives[0]);
		i++;
	}
	return (alternatives[1]);
}

//main parser function
//input for token stream is head of lexer, parent input is null at first
void	ft_parse(t_shell_data *shell_data, char *production, t_leaf *parent,
	t_token *token_stream)
{
	char	*alternative;
	char	*symbol;

	alternative = NULL;
	if (shell_data->parse_fail || (!token_stream && ft_printf(2, "Syntax Error\n") && shell_data->parse_fail) || (!token_stream && !production && !shell_data->lexer->unmatched))
		return ;
	while (contains_c(production, '|'))
	{
		alternative = match_alternative(shell_data->lexer, token_stream,
				(char *[]){alternative, ft_chop(production, '|')});
	}
	if (!alternative && ft_printf(2, "Syntax Error near token %s\n", token_stream->lexeme) && shell_data->parse_fail--)
		return ;
	parent = terminal_to_leaf(shell_data->ast, parent, token_stream);
	while (contains_c(alternative, ' '))
	{
		symbol = ft_chop(alternative, ' ');
		if (contains_non_terminal(symbol))
			ft_parse(shell_data, get_production(symbol), parent,
				split_stream(&token_stream));
	}
}
