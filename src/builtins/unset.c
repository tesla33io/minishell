/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 21:08:37 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/06 17:43:59 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"
#include "../../lib/libft/libft.h"

int	unset_builtin(t_Command *unset)
{
	int		i;
	int		j;

	if (!unset)
		return (builtin_failed(BUILTIN_FAILED, "unset", 1));
	gc_set_storage(5);
	i = 1;
	while (unset->args[i])
	{
		j = 0;
		while (unset->envpv[j]
			&& ft_strncmp(unset->envpv[j], unset->args[i],
				ft_strlen(unset->args[i])) != 0)
			j++;
		if (!unset->envpv[j] && ++i)
			continue ;
		unset->envpv = ft_strarray_remove_by_index(unset->envpv, (size_t) j);
		if (!unset->envpv)
			return (1);
	}
	gc_set_storage(0);
	return (0);
}
