#include "../../include/minishell.h"
#include <stdio.h>

char	*ft_chop(char *str, char c)
{
	int		i;
	int		len;
	char	*chop;

	i = 0;
	len = 0;
	chop = NULL;
	while (str[len] && str[len] != c)
		len++;
	chop = gc_malloc((len + 1) * sizeof(char));
	while (str[i] && i < len)
	{
		chop[i] = str[i];
		i++;
	}
	chop[i++] = '\0';
	len = i;
	i = 0;
	ft_memmove(str, str + len, (ft_strlen(str) - len));
	ft_bzero(str + (ft_strlen(str) - len), len);
	return (chop);
}

// TODO they should work even if terminal is in the middle

char	*contains_terminal(char *production)
{
	int		i;
	int		len;
	int		word;

	i = -1;
	len = 0;
	word = 0;
	while (production[++i])
	{
		if (is_lower(production[i]) && word)
			word--;
		else if (word || (is_upper(production[i]) && ++word))
			len++;
	}
	if (!len)
		return (NULL);
	i = -1;
	while (production[++i] && !is_upper(production[i]))
		;
	return (ft_substr(production, i, len));
}

char	*contains_non_terminal(char *production)
{
	int		i;
	int		len;
	int		word;

	i = -1;
	len = 0;
	word = 0;
	while (production[++i])
	{
		if (is_upper(production[i]) && word)
			word--;
		else if (word || (is_lower(production[i]) && ++word))
			len++;
	}
	if (!len)
		return (NULL);
	i = -1;
	while (production[++i] && !is_lower(production[i]))
		;
	return (ft_substr(production, i, len));
}

t_leaf	*terminal_to_leaf(t_ast *ast, t_leaf *parent, t_token *token_stream)
{
	t_token	*travel;

	travel = token_stream;
	while (travel)
	{
		if (travel->matched)
		{
			if (!parent->terminal)
				parent = append_leaf(ast->root, parent, travel);
			else if (!parent->left->terminal)
				parent = append_leaf(parent->left, parent, travel);
			else if (!parent->right->terminal)
				parent = append_leaf(parent->right, parent, travel);
			else
			{
				printf("%s:%d (%s): parent already has 2 children\n",
					__FILE__, __LINE__, __FUNCTION__);
			}
		}
		travel = travel->next;
	}
	return (parent);
}

t_leaf	*append_leaf(t_leaf *leaf, t_leaf *parent, t_token *tok)
{
	if (!leaf)
		printf("issue, not malloced leaf when appending\n");
	leaf->token = tok->token;
	leaf->terminal = tok->lexeme;
	leaf->parent = parent;
	leaf->left = gc_malloc(sizeof(t_leaf));
	leaf->left->terminal = NULL;
	leaf->right = gc_malloc(sizeof(t_leaf));
	leaf->right->terminal = NULL;
	tok->token = TRASH;
	return (leaf);
}

char	*get_production(char *production)
{
	int	i;

	i = 0;
	while (production[i])
		i++;
	if (!ft_strncmp(production, "complete_command", i))
		return (ft_strdup(COMPLETE_COMMAND));
	else if (!ft_strncmp(production, "pipe_sequence", i))
		return (ft_strdup(PIPE_SEQUENCE));
	else if (!ft_strncmp(production, "command", i))
		return (ft_strdup(COMMAND));
	else if (!ft_strncmp(production, "simple_command", i))
		return (ft_strdup(SIMPLE_COMMAND));
	else
		return (NULL);
}
