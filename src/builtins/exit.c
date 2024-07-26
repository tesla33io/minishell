/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 21:15:07 by astavrop          #+#    #+#             */
/*   Updated: 2024/07/26 21:17:29 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"

#include <stdlib.h>

int	exit_builtin(t_Command *e)
{
	gc_free_gc();
	ft_strarray_free(e->envpv);
	if (e->args && e->args[1])
		exit(ft_atoi(e->args[1]));
	return (ft_atoi(e->args[1]));
}
