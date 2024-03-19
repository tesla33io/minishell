/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:58:11 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/19 22:58:12 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/executor.h"
#include <stdio.h>

void	print_command(t_SimpleCommand	*cmd)
{
	int	i;

	if (cmd->bin)
		printf("Binary: %s\n", cmd->bin);
	if (cmd->args)
	{
		i = -1;
		while (cmd->args[++i])
			printf("Arg: %s\n", cmd->args[i]);
	}
}
