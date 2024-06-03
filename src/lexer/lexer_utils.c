#include "minishell.h"

//ft to find the matching character for an enclosed section, such as a double quoted string, that starts with the first member of the pair
int	find_match(char *str, char c)
{
	int i;

	i = 1; //0 positin is where the first part of the pair is
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

//take out the trash token
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
			lexer->tkn_count--;
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


