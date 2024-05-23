/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:07:14 by astavrop          #+#    #+#             */
/*   Updated: 2024/05/24 20:08:31 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"

#include <unistd.h>
#include <stdio.h> /* DELETE */

int	execute_command_in_child(t_Command *command)
{
	pid_t	child_pid;

	child_pid = fork();
	if (child_pid < 0)
		return (fork_fail());
	if (child_pid == 0)
	{
		// command->envpv = generate_envpv(command->envp_ht);
		dup2(command->in_fd, STDIN_FILENO);
		dup2(command->out_fd, STDOUT_FILENO);
		printf("nevp: %p\n", (void *) command->envpv);
		if (execve(command->bin_name, command->args, command->envpv) < 0)
			return (execve_fail());
	}
	return (child_pid);
}
