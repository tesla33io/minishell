/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:36:54 by ltreser           #+#    #+#             */
/*   Updated: 2024/08/16 19:20:04 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"
#include "../../include/minishell.h"

char	*insert_var(char *str, char *value, int start)
{
	int		i;
	char	*ret;

	i = 0;
	ret = gc_malloc(ft_strlen(str) + 1);
	while (i < start)
	{
		ret[i] = str[i];
		i++;
	}
	ret = ft_strjoin(ret, value);
	ret = ft_strjoin(ret, str + i);
	return (ret);
}

char	*get_value(char *variable, char **envp)
{
	int		i;
	char	*value;

	i = 0;
	if (variable[i] == '?')
		value = ft_itoa(set_last_exit_code(0, 'g'));
	else
		value = ft_getenv(envp, variable);
	if (!value)
		return (NULL);
	else
		return (ft_strdup(value));
}

char	*var_name(char *str, char *flag)
{
	int	i;

	i = 1;
	if (ft_isdigit(str[i]) || !str[i])
		return (NULL);
	if (str[i] == '?')
		return (ft_strdup("?"));
	while (str[i] && flag[i] == 'Y' && (str[i] == '_' || ft_isalpha(str[i])
			|| (ft_isdigit(str[i]) && i > 1)))
		i++;
	if (!(str[i] && flag[i] == 'Y' && (str[i] == '_' || ft_isalpha(str[i])
				|| (ft_isdigit(str[i]) && i > 1))))
		i--;
	return (ft_substr(str, 1, i));
}

static char	*rem_varname(t_leaf *leaf, int i, char *variable)
{
	return (ft_strjoin(ft_substr(leaf->terminal, 0, i), ft_substr(leaf->terminal
				+ i + 1 + ft_strlen(variable), 0, ft_strlen(leaf->terminal + i
					+ 1 + ft_strlen(variable)))));
}

void	var_expand(t_leaf *leaf, t_command *cmd)
{
	int		i;
	char	*variable;
	char	*val;

	i = -1;
	while (leaf && leaf->terminal && leaf->terminal[0] && leaf->terminal[++i])
	{
		variable = NULL;
		val = NULL;
		if (leaf->terminal[i] == '$' && leaf->var[i] == 'Y')
		{
			variable = var_name(leaf->terminal + i, leaf->var + i);
			if (!variable && ++i)
				continue ;
			val = get_value(variable, cmd->envpv);
			leaf->terminal = rem_varname(leaf, i, variable);
			if (val)
			{
				leaf->terminal = insert_var(leaf->terminal, val, i);
				leaf->var = insert_var(leaf->var,
						ft_memset(gc_malloc(ft_strlen(val) + 1), 'N',
							ft_strlen(val)), i);
			}
		}
	}
}
