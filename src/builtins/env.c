/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:40:08 by astavrop          #+#    #+#             */
/*   Updated: 2024/04/29 21:31:34 by astavrop         ###   ########.fr       */
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
		{
			if (ft_strchr(cmd->envp[i], '=') != NULL)
				ft_putendl_fd(cmd->envp[i], 1);
			i++;
		}
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

char	**ft_envdup(char *envp[])
{
	char	**new_envp;
	int		i;

	i = 0;
	while (envp[i] != NULL)
		i++;
	new_envp = ft_malloc(NULL, sizeof(char *) * (i + 1));
	i = -1;
	while (envp[++i] != NULL)
		new_envp[i] = envp[i];
	new_envp[i] = NULL;
	return (new_envp);
}
