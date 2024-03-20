/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:33:20 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/20 16:33:20 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/executor.h"
#include <stdlib.h>
#include <stdio.h>

void	free_str_list(char	**lst)
{
	int	i;

	i = -1;
	if (!lst)
		return ;
	while (lst[++i])
		free(lst[i]);
	free(lst);
}
