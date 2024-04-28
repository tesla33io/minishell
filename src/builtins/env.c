/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:40:08 by astavrop          #+#    #+#             */
/*   Updated: 2024/04/28 19:06:27 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft/libft.h"
#include "../../include/executor.h"

#include <stdlib.h>

void	ft_env(t_SimpleCommand *cmd)
{
	int	i;

	if (!cmd->envp)
		ft_putendl_fd("env: no environment variables", 2);
	else
	{
		i = 0;
		while (cmd->envp[i] != NULL)
			ft_putendl_fd(cmd->envp[i++], 1);
	}
}

char	*ft_getenv(char *envp[], char *name)
{
	int	i;

	if (!envp)
		ft_putendl_fd("ft_getenv: no environment variables", 2);
	else
	{
		i = 0;
		while (envp[i] != NULL)
		{
			if (ft_strncmp(name, envp[i], ft_strlen(name)) == 0)
				return (envp[i]);
			i++;
		}
	}
	return (NULL);
}
