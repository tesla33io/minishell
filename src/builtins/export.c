/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:04:55 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/06 17:29:56 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft/libft.h"
#include "../../include/execution.h"

#include <stdio.h> /* DELETE */

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
		exprt->envpv = ft_strarray_append(exprt->envpv, exprt->args[i]);
		i++;
	}
	gc_set_storage(0);
	return (0);
}
