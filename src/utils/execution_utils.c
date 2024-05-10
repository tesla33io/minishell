/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:59:58 by astavrop          #+#    #+#             */
/*   Updated: 2024/05/10 18:22:38 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "../../include/executor.h"
#include "../../lib/libft/libft.h"

bool	is_builtint(char *bin, char *b_list[])
{
	int	i;

	i = 0;
	while (b_list[i])
	{
		if (ft_strncmp(bin, b_list[i], ft_strlen(b_list[i])) == 0)
			return (true);
		i++;
	}
	return (false);
}

int	check_command(t_SimpleCommand **command)
{
	t_SimpleCommand	*cmd;

	cmd = *(command);
	if (!cmd->bin || !cmd->args)
		return (-1);
	// binary lookup coming soon..................
	return (-1);
}
