/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:34:57 by astavrop          #+#    #+#             */
/*   Updated: 2024/04/21 16:31:17 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/executor.h"
#include <stdlib.h>
#include <stdio.h>

#define R			"\x1b[0m"
#define BLACK		"\x1b[30m"
#define RED			"\x1b[31m"
#define GREEN		"\x1b[32m"
#define YELLOW		"\x1b[33m"
#define BLUE		"\x1b[34m"
#define MAG			"\x1b[35m"
#define CYAN		"\x1b[36m"
#define WHITE		"\x1b[37m"

t_SimpleCommand	*cmd_gen(char *bin, char **args, char **envp, int in_fd,
		int out_fd, int pipefd[2])
{
	t_SimpleCommand	*cmd;

	cmd = malloc(sizeof(t_SimpleCommand));
	cmd->bin = bin;
	cmd->args = args;
	cmd->envp = envp;
	cmd->in_fd = in_fd;
	cmd->out_fd = out_fd;
	cmd->pipefd[0] = pipefd[0];
	cmd->pipefd[1] = pipefd[1];
	return (cmd);
}

void	print_command(t_SimpleCommand	*cmd)
{
	printf("%s%s%s ", YELLOW, cmd->bin != NULL ? cmd->bin : "<no bin>", R);
	if (cmd->args[0])
	{
		for (int i = 1; cmd->args[i] != NULL; i++)
			printf("%s%s%s ", GREEN, cmd->args[i], R);
	}
	printf("%s<in_fd=%d>%s ", MAG, cmd->in_fd >= 0 ? cmd->in_fd : -1, R);
	printf("%s<out_fd=%d>%s ", MAG, cmd->out_fd >= 0 ? cmd->in_fd : -1, R);
	printf("%s<pipe[%d, %d]>%s\n", CYAN,
		cmd->pipefd[RDEND] >= 0 ? cmd->pipefd[RDEND] : -1,
		cmd->pipefd[WREND] >= 0 ? cmd->pipefd[WREND] : -1,
		R);
}
