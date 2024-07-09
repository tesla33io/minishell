#include "minishell.h"

char *ft_chop(char *str, char c)
{
	int i;
	int len;
	char *chop;
	
	i = 0;
	len = 0;
	while (str[len] && str[len] != c)
		len++;
	chop = malloc((len + 1) * sizeof(char));
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

//TODO they should work even if terminal is in the middle

char    *contains_terminal(char *production)
{
        int i;
        int len;
        char *terminal;
	int word;

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
        if (len)
                terminal = malloc(len * sizeof(char));
        else
                return (NULL);
        i = -1;
        len = 0;
        while (production[++i])    //TODO build loop here

                if ((is_upper(production[i]) || && len++)
                        terminal[i] = production[i];
        terminal[len] = '\0';
        return (terminal);
}

char *contains_non_terminal(char *production)
{
        int i;
        int len;
        char *non_terminal;
	int word;

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
        if (len)
                non_terminal = malloc(len * sizeof(char));
        else
                return (NULL);
        i = -1;
        len = 0;
        while (production[++i])
                if (is_upper(production[i]) && len++)
                        non_terminal[i] = production[i];
        non_terminal[len] = '\0';
        return (non_terminal);
}

t_leaf  *terminal_to_leaf(t_ast *ast, t_leaf *parent, t_token *token_stream)
{
    t_token *travel;

    travel = token_stream;
    while (travel)
    {
        if (travel->matched)
        {
            if (!parent)
                parent = append_leaf(ast->root, parent, travel);
            else if (!parent->left)
                parent = append_leaf(parent->left, parent, travel);
            else
                parent = append_leaf(parent->right, parent, travel);
        }
        travel = travel->next;
    }
    return (parent);
}

t_leaf *append_leaf(t_leaf *leaf, t_leaf *parent, t_token *tok)
{
    leaf = malloc(sizeof(t_leaf*));
    leaf->token = tok->token;
    leaf->terminal = tok->lexeme;
    printf("appending : %s\n", tok->lexeme);
    if (parent)
        leaf->parent = parent;
    else
        leaf->parent = NULL;
    leaf->left = NULL;
    leaf->right = NULL;
    tok->token = TRASH;
    return (leaf);
}

