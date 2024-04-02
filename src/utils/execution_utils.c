/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 13:48:01 by astavrop          #+#    #+#             */
/*   Updated: 2024/04/02 20:00:50 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/executor.h"
#include "../../lib/libft/libft.h"

#include <stdlib.h>
#include <unistd.h>

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
			// cmd->args[0] = bin_path;
			return (0);
		}
	}
	free(bin_path);
	return (-1);
}

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
