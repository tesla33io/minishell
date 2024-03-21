/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:58:11 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/19 22:58:12 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/executor.h"
#include "../../lib/libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	find_bin(t_SimpleCommand *cmd)
{
	char	*env_path;
	char	**path_list;
	char	*bin_path;
	char	*tmp_path;
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
		tmp_path = ft_strjoin(path_list[i], "/");
		bin_path = ft_strjoin(tmp_path, cmd->bin);
		free(tmp_path);
		if (access(bin_path, F_OK) == 0)
		{
			if (access(bin_path, X_OK) == 0)
			{
				cmd->bin = bin_path;
				cmd->args[0] = bin_path;
				free_str_list(path_list);
				return ;
			}
		}
		free(bin_path);
	}
	free(bin_path);
	free_str_list(path_list);
	printf("Error [11]: `%s` is not on $PATH.\n", cmd->bin);
	return ;
}

static int	cmd_check(t_SimpleCommand *cmd)
{
	if (!cmd->bin)
		return (-1);
	if (!cmd->args)
		return (-1);
	if (ft_strncmp(cmd->bin, cmd->args[0], ft_strlen(cmd->bin)) != 0)
		return (-1);
	return (0);
}

int	cmd_exe(t_SimpleCommand *cmd)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		printf("Fork failure!\n");
	if (pid == 0)
	{
		if (cmd_check(cmd) != 0)
			exit(printf("Command execution failed.\n"));
		find_bin(cmd);
		execve(cmd->bin, cmd->args, cmd->envp);
	}
	else
	{
		printf("Message from parent.\n");
	}
	return (0);
}

void	print_command(t_SimpleCommand	*cmd)
{
	int	i;

	if (cmd->bin)
		printf("Binary: %s\n", cmd->bin);
	if (cmd->args)
	{
		i = -1;
		while (cmd->args[++i])
			printf("Arg: %s\n", cmd->args[i]);
	}
}
