/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 21:08:37 by astavrop          #+#    #+#             */
/*   Updated: 2024/07/28 18:51:01 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"
#include "../../lib/libft/libft.h"

int	unset_builtin(t_Command *unset)
{
	int		i;
	int		j;

	if (!unset)
		return (-1);
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
			return (-1);
	}
	return (0);
}
