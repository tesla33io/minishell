/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:00:09 by astavrop          #+#    #+#             */
/*   Updated: 2024/05/26 21:10:16 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"

#include <unistd.h>
#include <stdlib.h>

int	execute_pipeline(t_Pipeline *pipeline)
{
	pid_t	*pids;
	pid_t	pid;
	int		pipefd[2][2];
	int		i;
	
	pids = ft_malloc(NULL, sizeof(*pids) * pipeline->num_cmds);
	i = 0;
	pipe(pipefd[i & 1]);
	pipe(pipefd[(i + 1) & 1]);
	while (i < pipeline->num_cmds)
	{
		pid = fork();
		if (pid == 0 && (ft_free_ptr(pids), 1))
		{
			execute_command_in_child(
					&pipeline->commands[i]->command, pipefd);
		}
	}
	return (0);
}
