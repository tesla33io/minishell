/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:05:09 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/30 14:47:18 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/executor.h"

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

/*******************************************************************************
 * plin - pipeline in                                                          *
 * plout - pipeline out                                                        *
 ******************************************************************************/
static void	assign_pipes(t_CommandNode *pipen, int pipefd[2],
		int plin, int plout)
{
	pipen->left->cmd->pipefd[RDEND] = plin;
	pipen->left->cmd->pipefd[WREND] = pipefd[WREND];
	pipen->right->cmd->pipefd[RDEND] = pipefd[RDEND];
	pipen->right->cmd->pipefd[WREND] = plout;
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
	assign_pipes(pipen, pipefd, 0, 1);
	pids[0] = cmd_exe(pipen->left->cmd);
	pids[1] = cmd_exe(pipen->right->cmd);
	waitpid(pids[0], &status, 0);
	waitpid(pids[1], &status, 0);
	return (w_check(status));
}
