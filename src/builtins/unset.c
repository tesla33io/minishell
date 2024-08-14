/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 21:08:37 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/14 21:30:29 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"
#include "../../include/builtins.h"
#include "../../lib/libft/libft.h"

int	unset_builtin(t_command *unset)
{
	int		i;

	if (!unset)
		return (builtin_failed(BUILTIN_FAILED, "unset"));
	gc_set_storage(5);
	i = 1;
	while (unset->args[i])
	{
		remove_env_var(unset->envpv, unset->args[i]);
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
	var = ft_strjoin(var, "=");
	while (envp[j] && ft_strncmp(envp[j], var, ft_strlen(var)) != 0)
		j++;
	if (!envp[j])
		return (0);
	envp[j] = ft_strdup("null");
	return (0);
}
