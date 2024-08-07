#include "../../include/minishell.h"

//ft to find the matching character for an enclosed section, such as a
//double quoted string, that starts with the first member of the pair
int	find_match(char *str, char c)
{
	int	i;

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

int	contains_token(t_token *head, t_tkntype type)
{
	while (head && head->token != type)
		head = head->next;
	if (!head)
		return (0);
	else
		return (1);
}

//TODO recode bc of change of list type
//take out the trash token, should keep tokenstream seemlessly connected
void	take_out_trash(t_token *head)
{
	t_token		*current;
	t_token		*previous;

	current = head;
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
	if (contains_token(head, TRASH))
		return (take_out_trash(head));
	else
		return ;
}

int	count_tokens(t_token *head)
{
	t_token	*travel;
	int		count;

	travel = head;
	count = 0;
	while (travel && ++count)
		travel = travel->next;
	return (count);
}
