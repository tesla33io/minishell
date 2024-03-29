/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:05:09 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/29 22:07:20 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/executor.h"

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

#define WREND 1
#define RDEND 0

static void	assign_pipes(t_CommandNode *pipen, int pipefd[2])
{
	pipen->left->cmd->pipefd[RDEND] = pipefd[RDEND];
	pipen->left->cmd->pipefd[WREND] = pipefd[WREND];
	pipen->right->cmd->pipefd[RDEND] = pipefd[RDEND];
	pipen->right->cmd->pipefd[WREND] = pipefd[WREND];
}

int	process_pipe(t_CommandNode *pipen)
{
	int	pipefd[2];
	int	pids[2];
	int	status;

	if (pipen->type != PIPE)
		return (FAIL);
	if (pipe(pipefd) != 0)
		exit(pipe_fail(pipefd));
	assign_pipes(pipen, pipefd);
	pids[0] = cmd_exe(pipen->left->cmd);
	pids[1] = cmd_exe(pipen->right->cmd);
	waitpid(pids[0], &status, 0);
	printf("DEBUG:: pid0: %d\n", status);
	waitpid(pids[1], &status, 0);
	printf("DEBUG:: pid1: %d\n", status);
	return (status);
}
