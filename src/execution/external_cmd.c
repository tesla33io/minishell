/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:07:14 by astavrop          #+#    #+#             */
/*   Updated: 2024/05/20 18:39:23 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"

#include <unistd.h>

int	execute_command_in_child(t_Command *command)
{
	pid_t	child_pid;
	char	**envpv;

	child_pid = fork();
	if (child_pid < 0)
		return (fork_fail());
	if (child_pid == 0)
	{
		dup2(command->in_fd, STDIN_FILENO);
		dup2(command->out_fd, STDOUT_FILENO);
		if (execve(command->bin_name, command->args) < 0)
			return (execve_fail());
	}
	return (child_pid);
}
