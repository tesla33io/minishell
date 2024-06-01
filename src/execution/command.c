/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:07:14 by astavrop          #+#    #+#             */
/*   Updated: 2024/06/01 18:12:51 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"
#include "../../include/colors.h"

#include <stdio.h> /* DELETE */
#include <unistd.h>
#include <stdlib.h> /* getenv() */

static void	setup_ipc(t_Command *cmd, int i,int pipefd[2][2], int num_cmds);

void execute_command_in_child(t_Command *command, int pipefd[2][2], int i, int num_cmds)
{
	char	*bin;

	setup_ipc(command, i, pipefd, num_cmds);

	bin = find_executable_on_path(getenv("PATH"), command->bin_name);
    printf("[%sDEBUG%s] - command to execute - %s\n", YEL, RESET, command->bin_name);
    print_cmd(command);

    if (execve(bin, command->args, command->envpv) < 0)
        execve_fail();
}

static void	setup_ipc(t_Command *cmd, int i,int pipefd[2][2], int num_cmds)
{
	// Setup input redirection
	if (cmd->in_fd != 0) {
		dup2(cmd->in_fd, STDIN_FILENO);
	} else if (i > 0) { 
		dup2(pipefd[(i - 1) % 2][0], STDIN_FILENO);
	}

	// Close the read end of the previous pipe
	if (i > 0) {
		close(pipefd[(i - 1) % 2][0]);
		close(pipefd[(i - 1) % 2][1]);
	}

	// Setup output redirection
	if (cmd->out_fd != 1) {
		dup2(cmd->out_fd, STDOUT_FILENO);
	} else if (i < num_cmds - 1) { 
		dup2(pipefd[i % 2][1], STDOUT_FILENO);
	}

	// Close the write end of the current pipe
	if (i < num_cmds - 1) {
		close(pipefd[i % 2][0]);
		close(pipefd[i % 2][1]);
	}
}
