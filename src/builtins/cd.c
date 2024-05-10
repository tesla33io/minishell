/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:59:32 by astavrop          #+#    #+#             */
/*   Updated: 2024/05/10 18:24:03 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtins.h"
#include "../../include/executor.h"
#include "../../lib/libft/libft.h"

#include <errno.h>
#include <string.h>
#include <unistd.h>

void	ft_cd(t_SimpleCommand *cmd)
{
	int	errnum;

	if (!cmd->args[1])
	{
		if (ht_get(cmd->envp_ht, "HOME") != NULL)
			chdir(ht_get(cmd->envp_ht, "HOME"));
	}
	else if (chdir(cmd->args[1]) != 0)
	{
		errnum = errno;
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(strerror(errnum), 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(cmd->args[1], 2);
	}
}
