/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:59:58 by astavrop          #+#    #+#             */
/*   Updated: 2024/04/26 19:58:10 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "../../include/executor.h"

bool	check_command(t_SimpleCommand **command)
{
	t_SimpleCommand	*cmd;

	cmd = *(command);
	if (!cmd->bin || !cmd->args || !cmd->envp)
		return (false);
	// binary lookup coming soon..................
	return (false);
}
