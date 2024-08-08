/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 21:08:37 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/08 21:54:16 by astavrop         ###   ########.fr       */
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
		if (ret == 2 && ++i)
			continue ;
		else if (ret == 1)
			return (1);
	//	j = 0;
	//	while (unset->envpv[j]
	//		&& ft_strncmp(unset->envpv[j], unset->args[i],
	//			ft_strlen(unset->args[i])) != 0)
	//		j++;
	//	if (!unset->envpv[j] && ++i)
	//		continue ;
	//	unset->envpv = ft_strarray_remove_by_index(unset->envpv, (size_t) j);
	//	if (!unset->envpv)
	//		return (1);
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
		j++;
	if (!envp[j])
		return (2);
	envp = ft_strarray_remove_by_index(envp, (size_t) j);
	if (!envp)
		return (1);
	return (0);
}
