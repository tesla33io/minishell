/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:54:33 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/14 21:30:26 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"

int	env_builtin(t_command *env)
{
	int		i;

	if (!env)
		return (builtin_failed(BUILTIN_FAILED, "env"));
	i = 0;
	while (env->envpv[i])
	{
		if (ft_strcmp("null", env->envpv[i]) == 0 && ++i)
			continue ;
		ft_putendl_fd(env->envpv[i], 1);
		i++;
	}
	return (0);
}
