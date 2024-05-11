/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:51:39 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/30 13:43:46 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/executor.h"

#include <asm-generic/errno-base.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int	pipe_fail(int pipefd[2])
{
	(void)pipefd;
	perror("pipe: ");
	pipefd = (int [2]){-1, -1};
	return (EPIPE);
}

int	execution_fail(char *cmd_bin)
{
	perror(cmd_bin);
	return (CNFOUND);
}

int	fork_fail(void)
{
	perror("fork: ");
	return (EAGAIN);
}
