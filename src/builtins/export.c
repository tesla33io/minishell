/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:04:55 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/10 21:45:12 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft/libft.h"
#include "../../include/execution.h"
#include "../../include/builtins.h"

#include <string.h>

static int	rm_existing(char **envp, char *var);

int	export_builtin(t_Command *exprt)
{
	int		i;

	if (!exprt)
		return (builtin_failed(BUILTIN_FAILED, "export", 1));
	i = 1;
	gc_set_storage(5);
	while (exprt->args[i])
	{
		if (!ft_strchr(exprt->args[i], '=') && ++i)
			continue ;
		if (rm_existing(exprt->envpv, exprt->args[i]))
			ft_putendl_fd("export: internal error! Restart the shell!", 2);
		exprt->envpv = ft_strarray_append(exprt->envpv, exprt->args[i]);
		i++;
	}
	gc_set_storage(0);
	return (0);
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
