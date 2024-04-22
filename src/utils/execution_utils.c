/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 13:48:01 by astavrop          #+#    #+#             */
/*   Updated: 2024/04/21 16:31:51 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/executor.h"
#include "../../lib/libft/libft.h"

#include <stdlib.h>
#include <unistd.h>

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
int	bin_check(t_SimpleCommand *cmd, char *path)
{
	char	*bin_path;
	char	*tmp_path;

	tmp_path = ft_strjoin(path, "/");
	bin_path = ft_strjoin(tmp_path, cmd->bin);
	free(tmp_path);
	if (access(bin_path, F_OK) == 0)
	{
		if (access(bin_path, X_OK) == 0)
		{
			cmd->bin = bin_path;
			return (0);
		}
	}
	free(bin_path);
	return (-1);
}

/**
 * @brief Checks if the simple command is valid.
 *
 * This function checks if the simple command has a valid binary path
 * and arguments. It compares the binary path stored in the command structure
 * with the first argument of the command. If they match, it considers
 * the command valid and returns 0. Otherwise, it returns -1 to indicate
 * an invalid command.
 *
 * @param cmd Pointer to the simple command structure containing the details
 *            of the command.
 * @return Returns 0 if the simple command is valid.
 *         Returns -1 if the simple command is invalid.
 */
int	cmd_check(t_SimpleCommand *cmd)
{
	if (!cmd->bin)
		return (-1);
	if (!cmd->args)
		return (-1);
	if (ft_strncmp(cmd->bin, cmd->args[0], ft_strlen(cmd->bin)) != 0)
		return (-1);
	return (0);
}
