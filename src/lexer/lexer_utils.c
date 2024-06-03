#include "minishell.h"

int	find_match(char *str, char c)
{
	int i;

	i = 1;
	if (!str)
		return (0);
	if (!str[1])
		return (0);
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (i);
	else
		return (0);
}

void	take_out_trash(t_lex *lexer)
{
	int i;

	i = 0;
	while (i < lexer->tkn_count)
	{
		if (lexer->head->token == TRASH)
		{
			lexer->tail->next = lexer->head->next;
			lexer->head->next->prev = lexer->tail;
			lexer->head = lexer->tail->next;
		}
		lexer->tail = lexer->head;
		lexer->head = lexer->tail->next;
		i++;
	}
	while (i--)
	{
		lexer->head = lexer->tail;
		lexer->tail = lexer->tail->prev;
	}
}


