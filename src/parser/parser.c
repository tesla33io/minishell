/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:44:25 by ltreser           #+#    #+#             */
/*   Updated: 2024/08/17 22:15:28 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// return stoken stream up until trash, move pointer for token stream
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

int	terminal_located(t_token *ts, char *alternative, int pos, int prev_pos)
{
	char	*symbol;
	char	*tmp;
	t_token	*trvl;

	if (!alternative)
		return (0);
	tmp = ft_strdup(alternative);
	trvl = ts;
	while (contains_c(tmp, ' '))
	{
		symbol = ft_chop(tmp, ' ');
		if (contains_terminal(symbol))
			reset_variables(&pos, &prev_pos);
		while (trvl && contains_terminal(symbol) && ++pos)
		{
			if (trvl->token == tok2int(symbol) && (pos > 1 || (pos == 1
						&& trvl == ts)) && pos > prev_pos)
				break ;
			trvl = trvl->next;
		}
		if (!trvl && contains_terminal(symbol))
			return (0);
	}
	return (pos);
}

// helper function to find the correct alternative of a given production rule
char	*match_alternative(t_token *token_stream, char **alternatives)
{
	if (token_stream->lexeme && token_stream->lexeme[0] == '|')
		return (alternatives[0]);
	if ((count_words(alternatives[1], ' ') > count_tokens(token_stream))
		|| (!contains_non_terminal(alternatives[1])
			&& count_words(alternatives[1], ' ') < count_tokens(token_stream)))
		return (alternatives[0]);
	if (!terminal_located(token_stream, alternatives[1], 0, 0)
		&& contains_terminal(alternatives[1]))
		return (alternatives[0]);
	if (terminal_located(token_stream, alternatives[0], 0, 0)
		&& terminal_located(token_stream, alternatives[1], 0,
			0) > terminal_located(token_stream, alternatives[0], 0, 0))
		return (alternatives[0]);
	return (alternatives[1]);
}

void	match_tokens(t_token *token_stream, char *alternative)
{
	char	*symbol;
	char	*tmp;
	t_token	*travel;
	int		i;

	tmp = ft_strdup(alternative);
	i = 0;
	while (contains_c(tmp, ' '))
	{
		symbol = ft_chop(tmp, ' ');
		travel = token_stream;
		while (travel && contains_terminal(symbol))
		{
			if (travel->token == tok2int(symbol) && (i || (!i
						&& travel == token_stream)) && !travel->matched
				&& ++travel->matched)
				break ;
			travel = travel->next;
		}
		i++;
	}
}

// main parser function
// input for token stream is head of lexer, parent input is null at first
void	ft_parse(t_shell_data *sd, char *production, t_leaf *parent,
		t_token *token_stream)
{
	char	*alternative;
	char	*symbol;

	alternative = NULL;
	if (sd->parse_fail < 0 || (!token_stream && ft_dprintf(2, "Syntax Error\n")
			&& --sd->parse_fail) || (!token_stream && !production))
		return ;
	while (contains_c(production, '|'))
		alternative = match_alternative(token_stream, (char *[]){alternative,
				ft_chop(production, '|')});
	if (!alternative && ft_dprintf(2, "Syntax Error\n") && (--sd->parse_fail
			|| 1))
		return ;
	match_tokens(token_stream, alternative);
	parent = terminal_to_leaf(sd->ast, parent, token_stream);
	while (contains_c(alternative, ' '))
	{
		symbol = ft_chop(alternative, ' ');
		if (contains_non_terminal(symbol))
			ft_parse(sd, get_production(symbol), parent,
				split_stream(&token_stream));
	}
	return ;
}
