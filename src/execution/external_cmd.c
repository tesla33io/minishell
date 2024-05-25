/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:07:14 by astavrop          #+#    #+#             */
/*   Updated: 2024/05/25 18:42:14 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"
#include "../../include/colors.h"

#include <stdio.h> /* DELETE */
#include <unistd.h>

int	execute_command_in_child(t_Command *command)
{
	pid_t	child_pid;

	child_pid = fork();
	if (child_pid < 0)
		return (fork_fail());
	if (child_pid == 0)
	{
		if (find_executable_on_path(
					ft_getenv(command->envpv, "PATH="),
					command->bin_name) != 0)
			return (-1);
		printf("[%sDEBUG%s] - command to execute - %s\n", YEL, RESET, command->bin_name);
		dup2(command->in_fd, STDIN_FILENO);
		dup2(command->out_fd, STDOUT_FILENO);
		if (execve(command->bin_name, command->args, command->envpv) < 0)
			return (execve_fail());
	}
	return (child_pid);
}
