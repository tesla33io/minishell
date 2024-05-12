/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:05:09 by astavrop          #+#    #+#             */
/*   Updated: 2024/05/12 15:06:59 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/executor.h"

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * @brief Assigns pipe file descriptors to command nodes within a pipeline.
 *
 * This function assigns pipe file descriptors to the left and right command
 * nodes within the provided pipeline represented by the command node.
 *
 * @param pipen Pointer to the command node representing the pipeline.
 * @param pipefd Array of two integers representing pipe file descriptors.
 *               - The first integer is the read end of the pipe.
 *               - The second integer is the write end of the pipe.
 */
static void	assign_pipes(t_CommandNode *pipen, int pipefd[2])
{
	pipen->left->cmd->pipefd[RDEND] = pipefd[RDEND];
	pipen->left->cmd->pipefd[WREND] = pipefd[WREND];
	pipen->right->cmd->pipefd[RDEND] = pipefd[RDEND];
	pipen->right->cmd->pipefd[WREND] = pipefd[WREND];
}

/**
 * @brief Executes a pipeline represented by a command node.
 *
 * This function executes a pipeline represented by the provided command node.
 * It creates a pipe, assigns pipe file descriptors to the command nodes,
 * executes the left and right commands of the pipeline, waits for the
 * child processes to finish, and returns an integer indicating the success
 * or failure of the operation.
 *
 * @param pipen - Pointer to the command node representing the pipeline.
 * @return an integer indicating the success or failure of the operation.
 *         - 0 indicates success.
 *         - Any non-zero value indicates failure.
 */
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
	pids[0] = execute_command(pipen->left->cmd);
	pids[1] = execute_command(pipen->right->cmd);
	close(pipefd[WREND]);
	close(pipefd[RDEND]);
	waitpid(pids[0], &status, 0);
	waitpid(pids[1], &status, 0);
	return (w_check(status));
}
