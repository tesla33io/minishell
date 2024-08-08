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

void	take_out_trash(t_token *head)
{
	t_token		*current;
	t_token		*previous;

	if (head && head->token == TRASH)
		head = head->next;
	if (!head)
		return ;
	current = head;
        previous = NULL;
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


//TODO redecide which char it should be
//single quotes are not expanded nor globbed
//double quptes are expanded but not globbed
//str is expanded and globbed
// char *var;

void	set_varflag(t_lex *lexer)
{
	int len;
	t_token *travel;

	len = 0;
	travel = lexer->head;
	while (travel)
	{
		if (travel->token == STR || travel->token == D_QUOTE)
		{
			len = ft_strlen(travel->lexeme) + 1 - 2 * (travel->token == D_QUOTE);
			travel->var = ft_memset(gc_malloc(len), 'Y', len);
			travel->var[len - 1] = '\0';
		}
		else
		{
			len = ft_strlen(travel->lexeme) + 1 - 2 * (travel->token == S_QUOTE);
			travel->var = ft_memset(gc_malloc(len), 'N', len);
			travel->var[len - 1] = '\0';
		}
		travel = travel->next;
	}
}

void	set_globflag(t_lex *lexer)
{
        int len;
        t_token *travel;

        len = 0;
        travel = lexer->head;
        while (travel)
        {   
                if (travel->token == STR)
                {   
                        len = ft_strlen(travel->lexeme) + 1;
                        travel->glob = ft_memset(gc_malloc(len), 'Y', len);
                        travel->glob[len - 1] = '\0';
                }   
                else
                {   
                        len = ft_strlen(travel->lexeme) + 1 - 2 * (travel->token == S_QUOTE || travel->token == D_QUOTE);
                        travel->glob = ft_memset(gc_malloc(len), 'N', len);
                        travel->glob[len - 1] = '\0';
                }   
                travel = travel->next;
        }   
}

