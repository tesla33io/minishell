/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 21:08:37 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/10 21:40:27 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"
#include "../../include/builtins.h"
#include "../../lib/libft/libft.h"

int	unset_builtin(t_Command *unset)
{
	int		i;
	int		ret;

	if (!unset)
		return (builtin_failed(BUILTIN_FAILED, "unset", 1));
	gc_set_storage(5);
	i = 1;
	while (unset->args[i])
	{
		ret = remove_env_var(unset->envpv, unset->args[i]);
		if (ret && ++i)
			continue ;
		i++;
	}
	gc_set_storage(0);
	return (0);
}

int	remove_env_var(char **envp, char *var)
{
	int		j;

	if (!envp || !var)
		return (1);
	j = 0;
	while (envp[j] && ft_strncmp(envp[j], var, ft_strlen(var)) != 0)
	{
		if (envp[j][ft_strlen(var)] != '=' && ++j)
			continue ;
		j++;
	}
	if (!envp[j])
		return (0);
	envp[j] = ft_strdup("null");
	return (0);
}
