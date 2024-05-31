/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:00:09 by astavrop          #+#    #+#             */
/*   Updated: 2024/05/31 20:34:05 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h> /* waitpid() */

#include <stdio.h> /* perror() */

int execute_pipeline(t_Pipeline *pipeline) {
    pid_t *pids = malloc(sizeof(pid_t) * pipeline->num_cmds);
    int pipefd[2][2];
    int i;

    if (!pids) {
        perror("malloc");
        return -1;
    }

    for (i = 0; i < pipeline->num_cmds; i++) {
        if (i < pipeline->num_cmds - 1) {
            if (pipe(pipefd[i % 2]) == -1) {
                perror("pipe");
                return -1;
            }
        }

        pids[i] = fork();
        if (pids[i] < 0) {
            perror("fork");
            return -1;
        } else if (pids[i] == 0) {
			if (i > 0)
				close(pipefd[(i - 1) % 2][1]);
			if (i < pipeline->num_cmds - 1)
				close(pipefd[i % 2][0]);
            execute_command_in_child(pipeline->commands[i], pipefd, i, pipeline->num_cmds);
        }

        if (i > 0) {
            close(pipefd[(i - 1) % 2][0]);
            close(pipefd[(i - 1) % 2][1]);
        }
    }

    close(pipefd[(i - 1) % 2][0]);
    close(pipefd[(i - 1) % 2][1]);

    for (i = 0; i < pipeline->num_cmds; i++) {
        waitpid(pids[i], NULL, 0);
    }

    free(pids);
    return 0;
}
