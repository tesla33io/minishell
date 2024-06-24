/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:04:55 by astavrop          #+#    #+#             */
/*   Updated: 2024/06/24 21:03:18 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft/libft.h"
#include "../../include/execution.h"

int	export_builtin(t_Command *exprt)
{
	int		i;

	if (!exprt)
		return (-1);
	i = 1;
	while (exprt->args[i])
	{
		if (!ft_strchr(exprt->args[i], '=') && ++i)
			continue ;
		exprt->envpv = ft_strarray_append(exprt->envpv, exprt->args[i]);
		i++;
	}
	return (0);
}
