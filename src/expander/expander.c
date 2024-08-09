#include "../../include/minishell.h"
#include "../../include/execution.h"

char *insert_var(char *str, char *value, int start)
{
	int i;
	char *ret;

	i = 0;
	ret = gc_malloc(ft_strlen(str));
	while (i < start)
	{
		ret[i] = str[i];
		i++;
	}
	ret = ft_strjoin(ret, value);
	ret = ft_strjoin(ret, str + i);
	return (ret);
}

char *get_value(char *variable)
{
	int i;
	char *value;

	i = 0;
	if (variable[i] == '?')
		value = ft_itoa(set_last_exit_code(0, 'g'));
	else
		value = getenv(variable);
	if (!value)
		return (NULL);
	else
		return (ft_strdup(value));
}

char *var_name(char *str, char *flag)
{
	int i;

	i = 1;
	if (ft_isdigit(str[i]))
		return (NULL);
	if (str[i] == '?')
		return (ft_strdup("?"));
	while (str[i] && flag[i] == 'Y' && (str[i] == '_' || ft_isalpha(str[i]) || (ft_isdigit(str[i]) && i > 1)))
		i++;
	if (!(str[i] && flag[i] == 'Y' && (str[i] == '_' || ft_isalpha(str[i]) || (ft_isdigit(str[i]) && i > 1))))
		i--;

	return (ft_substr(str, 1, i));
}
	

void	var_expand(t_leaf *leaf)
{
	int i;
	char *variable;
	char *value;

	i = -1;
	while (leaf->terminal[++i])
	{
		variable = NULL;
		value = NULL;
		if (leaf->terminal[i] == '$' && leaf->var[i] == 'Y')
		{
			variable = var_name(leaf->terminal + i, leaf->var + i);
			if (!variable)
				continue;
			value = get_value(variable);
			leaf->terminal = ft_strjoin(ft_substr(leaf->terminal, 0, i), leaf->terminal + i + 1 + ft_strlen(variable));
			if (value)
				leaf->terminal = insert_var(leaf->terminal, value, i);
		}
	}	
}
