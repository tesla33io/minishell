/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:00:09 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/01 23:10:11 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h> /* waitpid() */
#include <stdbool.h>

#include <stdio.h> /* perror() */

static int	look_after_children(int num_cmds, int *pids);
static void	destroy_pipe(int pipefd[2][2], int i);

int	execute_pipeline(t_Pipeline *pl)
{
	pid_t	*pids;
	int		pipefd[2][2];
	int		i;

	pids = gc_malloc(sizeof(pid_t) * pl->num_cmds);
	if (!pids)
		return (-1);
	i = -1;
	while (++i < pl->num_cmds)
	{
		if (i < pl->num_cmds - 1)
		{
			if (pipe(pipefd[i % 2]) == -1)
				return (perror("pipe"), -1);
		}
		pids[i] = fork();
		if (pids[i] < 0)
			return (perror("fork"), -1);
		else if (pids[i] == 0)
			execute_command_in_child(pl->commands[i], pipefd, i, pl->num_cmds);
		if (i > 0)
			destroy_pipe(pipefd, (i - 1) % 2);
	}
	look_after_children(pl->num_cmds, pids);
	return (0);
}

static void	destroy_pipe(int pipefd[2][2], int i)
{
	close(pipefd[i][0]);
	close(pipefd[i][1]);
}

static int	look_after_children(int num_cmds, int *pids)
{
	int		i;
	int		status;
	int		ret;

	i = 0;
	ret = 0;
	while (i < num_cmds)
	{
		waitpid(pids[i], &status, 0);
		if (WIFSIGNALED(status))
			ret = WTERMSIG(status);
		if (WIFEXITED(status))
			ret = WEXITSTATUS(status);
		i++;
	}
	return (ret);
}
