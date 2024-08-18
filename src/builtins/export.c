/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:04:55 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/18 15:44:52 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft/libft.h"
#include "../../include/execution.h"
#include "../../include/builtins.h"

#include <string.h>

static int	rm_existing(char **envp, char *var);
static void	not_valid_identifier(char *id);
static int	check_nvi(char *str);

int	export_builtin(t_command *exprt)
{
	int		i;
	int		err;

	if (!exprt)
		return (builtin_failed(BUILTIN_FAILED, "export"));
	i = 1;
	err = 0;
	gc_set_storage(5);
	while (exprt->args[i])
	{
		if ((!ft_strchr(exprt->args[i], '=')
				|| check_nvi(exprt->args[i])))
		{
			not_valid_identifier(exprt->args[i++]);
			err |= 1;
			continue ;
		}
		if (rm_existing(exprt->envpv, exprt->args[i]))
			ft_putendl_fd("export: internal error! Restart the shell!", 2);
		exprt->envpv = ft_strarray_append(exprt->envpv, exprt->args[i]);
		i++;
	}
	gc_set_storage(0);
	return (err);
}

static int	rm_existing(char **envp, char *var)
{
	char	*name;
	int		i;

	i = 0;
	while (var[i] && var[i] != '=')
		i++;
	name = ft_substr(var, 0, (size_t) i);
	return (remove_env_var(envp, name));
}

static void	not_valid_identifier(char *id)
{
	ft_putstr_fd("export: `", 2);
	if (id)
		ft_putstr_fd(id, 2);
	ft_putendl_fd("': not a valid identifier", 2);
}

static int	check_nvi(char *str)
{
	int	i;

	i = 0;
	if (str[i] >= '0' && str[i] <= '9')
		return (1);
	while (str[i] && str[i] != '=')
	{
		if ((str[i] >= 'A' && str[i] <= 'Z')
			|| (str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= '0' && str[i] <= '9')
			|| str[i] == '_')
			i++;
		else
			return (1);
	}
	if (!str[i + 1])
		return (1);
	return (0);
}
