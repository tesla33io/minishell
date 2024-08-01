/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:18:45 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/01 19:26:03 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft/libft.h"
#include "../../include/execution.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <sys/types.h>
#include <sys/wait.h>

static void	read_heredoc(const char *delim, int wrfd);

int	start_heredoc(const char *delim)
{
	pid_t	cpid;
	int		pipefd[2];

	if (pipe(pipefd) < 0)
		return (-1);
	cpid = fork();
	if (cpid == 0)
	{
		close(pipefd[0]);
		read_heredoc(delim, pipefd[1]);
		close(pipefd[1]);
		gc_free_gc(0);
		gc_free_gc(5);
		exit(0);
	}
	else if (cpid > 0 && (close(pipefd[1]), 1))
	{
		waitpid(cpid, NULL, 0);
		return (pipefd[0]);
	}
	return (-1);
}

static void	read_heredoc(const char *delim, int wrfd)
{
	char	*line_buffer;

	line_buffer = readline("> ");
	while (line_buffer != NULL)
	{
		if (strncmp(line_buffer, delim, strlen(delim)) == 0)
			break ;
		write(wrfd, line_buffer, strlen(line_buffer));
		write(wrfd, "\n", 1);
		free(line_buffer);
		line_buffer = readline("> ");
	}
	free(line_buffer);
}
