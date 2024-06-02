/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:18:45 by astavrop          #+#    #+#             */
/*   Updated: 2024/06/02 21:21:55 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft/libft.h"
#include "../../include/execution.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <sys/types.h>

/*void	read_heredoc(const char *delim, int wrfd)
{
	char	*line_buffer;

	line_buffer = readline("> ");
	while (line_buffer != NULL)
	{
		if (ft_strncmp(line_buffer, delim, ft_strlen(delim)) == 0)
			break ; // end of here doc (free)
		write(wrfd, &line_buffer, ft_strlen(line_buffer));
		printf("[printf]:: %s", line_buffer);
		line_buffer = readline("\n> ");
	}
}

int	start_heredoc(char *delim)
{
	pid_t	cpid;
	int		pipefd[2];  better name ?
	if (pipe(pipefd) < 0)
		return (-1);
	cpid = fork();
	if (cpid == 0 && close(pipefd[0]))
		read_heredoc(delim, pipefd[1]);
	else if (cpid > 0 && close(pipefd[1]))
		return (pipefd[0]);
	return (-1);
}*/

void read_heredoc(const char *delim, int wrfd) {
    char *line_buffer;

    line_buffer = readline("> ");
    while (line_buffer != NULL) {
        if (strncmp(line_buffer, delim, strlen(delim)) == 0) {
            free(line_buffer);
            break; // end of here doc
        }
        write(wrfd, line_buffer, strlen(line_buffer));
        write(wrfd, "\n", 1); // add newline after each input line
        printf("[printf]:: %s\n", line_buffer);
        free(line_buffer);
        line_buffer = readline("> ");
    }
}

int start_heredoc(const char *delim) {
    pid_t cpid;
    int pipefd[2];

    if (pipe(pipefd) < 0)
        return -1;

    cpid = fork();
    if (cpid == 0) {
        close(pipefd[0]); // Close the read end in the child process
        read_heredoc(delim, pipefd[1]);
        close(pipefd[1]); // Close the write end before exiting
        exit(0);
    } else if (cpid > 0) {
        close(pipefd[1]); // Close the write end in the parent process
        return pipefd[0]; // Return the read end to the parent
    }
    return -1; // Fork failed
}
