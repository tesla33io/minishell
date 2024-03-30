/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:58:11 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/30 14:48:30 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/executor.h"
#include "../../lib/libft/libft.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define INVALID_CMD_ERR_MSG "Invalid command"

void	find_bin(t_SimpleCommand *cmd)
{
	char	*env_path;
	char	**path_list;
	int		i;

	env_path = getenv("PATH");
	if (!env_path)
		return ;
	path_list = ft_split(env_path, ':');
	if (!path_list)
		return ;
	i = -1;
	while (path_list[++i])
	{
		if (bin_check(cmd, path_list[i]) == 0)
		{
			free_str_list(path_list);
			return ;
		}
	}
	free_str_list(path_list);
}


/*******************************************************************************
 * Modes:                                                                      *
 * `l` - indicates that current pipe is for left command of the pipeline       *
 * `r` - indicates that current pipe is for right command of the pipeline      *
 ******************************************************************************/
void	set_pipes(t_SimpleCommand *cmd, int mode)
{
	if (mode == 'l')
	{
		dprintf(2, "Setting pipes...\n");
		dup2(cmd->pipefd[WREND], STDOUT_FILENO);
		dup2(cmd->pipefd[RDEND], STDIN_FILENO);
	}
}

int	cmd_exe(t_SimpleCommand *cmd)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		fork_fail();
	if (pid == 0)
	{
		set_pipes(cmd, 'l');
		if (cmd_check(cmd) != 0)
			(perror(INVALID_CMD_ERR_MSG), exit(FAIL));
		find_bin(cmd);
		if (execve(cmd->bin, cmd->args, cmd->envp) == -1)
			exit(execution_fail(cmd->bin));
	}
	return (pid);
}
