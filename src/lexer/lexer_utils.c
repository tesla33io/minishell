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


//TODO recode bc of change of list type
//take out the trash token, should keep tokenstream seemlessly connected

void	take_out_trash(t_token *head)
{
	t_token *current;
	t_token *previous;
	current  = head;
	previous = NULL;
	if (head && head->token == TRASH)
		head = head->next;
	if (!head)
		return ;
	while (current)
	{
		if (current->token == TRASH)
			previous->next = current->next;
		previous = current;
		current = current->next;
	}
	return ;	
}

int count_tokens(t_token *head)
{
	t_token *travel;
	int count;

	travel = head;
	count = 0;
	while (travel && ++count)
		travel = travel->next;
	return (count);
}
	

/*
void	take_out_trash(t_lex *lexer) //TODO should have condition for when nothing is left/one token is left/etc - error handling
{
	int i;

	i = 0;
	while (i < lexer->tkn_count) //this is not perfect yet, incrementing and decrementing for while condition at the same time can go wrong, TODO find better way
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
*/

