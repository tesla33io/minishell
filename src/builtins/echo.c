/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 20:59:23 by astavrop          #+#    #+#             */
/*   Updated: 2024/04/28 19:05:18 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtins.h"
#include "../../include/executor.h"
#include "../../lib/libft/libft.h"

#include <stdbool.h>

void	ft_echo(t_SimpleCommand *cmd)
{
	int		i;
	bool	new_line;

	if (!cmd->args[1])
		return ;
	new_line = true;
	i = 0;
	if (ft_strncmp(cmd->args[1], "-n", 2) == 0)
	{
		new_line = false;
		i++;
	}
	while (cmd->args[i])
	{
		ft_putstr_fd(cmd->args[i], 1);
		if (cmd->args[i + 1])
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (new_line)
		ft_putstr_fd("\n", 1);
}
