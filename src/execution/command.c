/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:07:14 by astavrop          #+#    #+#             */
/*   Updated: 2024/05/31 20:33:43 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"
#include "../../include/colors.h"

#include <stdio.h> /* DELETE */
#include <unistd.h>
#include <stdlib.h> /* getenv() */

void execute_command_in_child(t_Command *command, int pipefd[2][2], int i, int num_cmds) {
	char	*bin;

    if (i > 0) {
        dup2(pipefd[(i - 1) % 2][0], STDIN_FILENO);
        close(pipefd[(i - 1) % 2][1]);
    }
    if (i < num_cmds - 1) {
        dup2(pipefd[i % 2][1], STDOUT_FILENO);
        close(pipefd[i % 2][0]);
    }

    bin = find_executable_on_path(getenv("PATH"), command->bin_name);
    printf("[%sDEBUG%s] - command to execute - %s\n", YEL, RESET, command->bin_name);
    print_cmd(command);

    if (execve(bin, command->args, command->envpv) < 0) {
        execve_fail();
    }
}
