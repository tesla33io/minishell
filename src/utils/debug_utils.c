/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:34:57 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/21 20:34:57 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/executor.h"
#include <stdlib.h>

t_SimpleCommand	*cmd_gen(char *bin, char **args, char **envp, char **in_fs,
		char **out_fs, int pipefd[2])
{
	t_SimpleCommand	*cmd;

	cmd = malloc(sizeof(t_SimpleCommand));
	cmd->bin = bin;
	cmd->args = args;
	cmd->envp = envp;
	cmd->in_fs = in_fs;
	cmd->out_fs = out_fs;
	cmd->pipefd[0] = pipefd[0];
	cmd->pipefd[1] = pipefd[1];
	return (cmd);
}
