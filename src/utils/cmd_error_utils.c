/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_error_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:29:35 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/17 00:16:59 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft/libft.h"
#include "../../include/execution.h"

#include <stdio.h>
#include <unistd.h>

int	fork_fail(void)
{
	perror("fork");
	return (1);
}

int	execve_fail(void)
{
	perror("execve");
	return (126);
}

int	cmd_not_found(char *name)
{
	set_last_exit_code(127, 's');
	if (access(name, X_OK) < 0)
		set_last_exit_code(126, 's');
	ft_putstr_fd(name, 2);
	ft_putendl_fd(": command not found", 2);
	return (127);
}
