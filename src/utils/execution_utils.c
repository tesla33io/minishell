/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:59:58 by astavrop          #+#    #+#             */
/*   Updated: 2024/05/11 21:10:27 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

#include "../../include/executor.h"
#include "../../include/builtins.h"
#include "../../lib/libft/libft.h"

static int	try_path_entry(t_SimpleCommand *cmd, char *path);

bool	is_builtint(char *bin, char *b_list[])
{
	int	i;

	i = 0;
	while (b_list[i])
	{
		if (ft_strncmp(bin, b_list[i], ft_strlen(b_list[i])) == 0)
			return (true);
		i++;
	}
	return (false);
}

int	run_builtin(t_SimpleCommand *cmd)
{
	if (ft_strcmp(cmd->bin, "echo") == 0)
		ft_echo(cmd);
	else if (ft_strcmp(cmd->bin, "cd") == 0)
		ft_cd(cmd);
	else if (ft_strcmp(cmd->bin, "pwd") == 0)
		ft_pwd(cmd);
	else if (ft_strcmp(cmd->bin, "env") == 0)
		ft_env(cmd);
	else if (ft_strcmp(cmd->bin, "export") == 0)
		ft_export(cmd);
	else if (ft_strcmp(cmd->bin, "unset") == 0)
		return (0); // TODO:
	else if (ft_strcmp(cmd->bin, "exit") == 0)
		return (0); // TODO:
	return (0);
}

int	check_command(t_SimpleCommand **command, bool is_full_path)
{
	t_SimpleCommand	*cmd;

	cmd = *(command);
	if (!cmd->bin || !cmd->args)
		return (FAIL);
	if (is_full_path)
	{
		if (access(cmd->bin, X_OK) != 0)
			return (NOXPERM);
		return (SUCCESS);
	}
	return (find_executable(command));
}

int	find_executable(t_SimpleCommand **cmd)
{
	char	*path;
	char	**path_entries;
	int		i;

	path = ht_get((*cmd)->envp_ht, "PATH");
	if (!path)
		return (FAIL);
	path_entries = ft_split(path, ':');
	if (!path_entries)
		return (FAIL);
	i = -1;
	while (path_entries[++i])
	{
		if (try_path_entry(*cmd, path_entries[i]) == SUCCESS)
		{
			ft_strarray_free(path_entries);
			return (SUCCESS);
		}
	}
	ft_strarray_free(path_entries);
	return (FAIL);
}

/**
 * @brief Checks if the binary executable file specified in the
 *        simple command exists and is executable.
 *
 * This function constructs the full path to the binary executable file
 * using the provided directory path and the binary name from the given
 * simple command. It then checks if the constructed binary path exists and is
 * executable. If the binary executable file exists and is executable, it
 * updates the command structure with the full binary path and returns 0.
 * Otherwise, it frees the allocated memory and returns -1.
 *
 * @param cmd Pointer to the simple command structure containing the details
 *            of the command.
 * @param path The directory path where the binary executable file is
 *             expected to be located.
 * @return Returns 0 if the binary executable file exists and is executable.
 *         Returns -1 otherwise.
 */
static int	try_path_entry(t_SimpleCommand *cmd, char *path)
{
	char	*bin_path;
	char	*tmp_path;

	tmp_path = ft_strjoin(path, "/");
	bin_path = ft_strjoin(tmp_path, cmd->bin);
	ft_free_ptr(tmp_path);
	if (access(bin_path, F_OK) == 0 && access(bin_path, X_OK) == 0)
	{
		cmd->bin = bin_path;
		return (0);
	}
	ft_free_ptr(bin_path);
	return (-1);
}
