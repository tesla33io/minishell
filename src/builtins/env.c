/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:54:33 by astavrop          #+#    #+#             */
/*   Updated: 2024/06/24 19:56:43 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"

int	env_builtin(t_Command *env)
{
	int	i;

	if (!env->envpv)
		return (-1);
	i = 0;
	while (env->envpv[i])
	{
		ft_putendl_fd(env->envpv[i], 1);
		i++;
	}
	return (0);
}
