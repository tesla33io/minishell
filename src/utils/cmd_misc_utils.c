/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_misc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:36:17 by astavrop          #+#    #+#             */
/*   Updated: 2024/05/26 19:46:55 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"
#include "../../include/colors.h"

#include <stdio.h>

void	print_cmd(t_Command *cmd)
{
	int		i;

	if (!cmd)
	{
		printf("[%sError%s] : %sNo command.%s", RED, RESET, YEL, RESET);
		return ;
	}
	if (cmd->bin_name)
		printf("[%sCMD%s] Binary: %s%s%s\n", YEL, RESET, BLU, cmd->bin_name, RESET);
	if (cmd->args)
	{
		printf("[%sCMD%s] Args: %s", YEL, RESET, BLU);
		i = -1;
		while (cmd->args[++i])
			printf("(%s%s%s)..", CYN, cmd->args[i], RESET);
		printf("(%sNULL%s)\n", CYN, RESET);
	}
	printf("[%sCMD%s] I/O: %s-> %d%s | %s%d ->%s\n",
			YEL, RESET, BLU, cmd->in_fd, RESET, BLU, cmd->out_fd, RESET);
}
