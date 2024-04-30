/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:40:08 by astavrop          #+#    #+#             */
/*   Updated: 2024/04/30 21:53:03 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft/libft.h"
#include "../../include/executor.h"
#include "../../include/builtins.h"

#include <stdlib.h>
#include <stdbool.h>

static void	print_envp(char *envp[], bool for_export);

void	ft_env(t_SimpleCommand *cmd)
{
	if (!cmd->envp)
		ft_putendl_fd("env: no environment variables", 2);
	else
		print_envp(cmd->envp, false);
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

void	ft_env_sorted(char *envp[])
{
	char			**sorted_envp;
	unsigned int	i;

	i = 0;
	while (envp[i])
		i++;
	sorted_envp = ft_envdup(envp);
	ft_strquicksort((const char **) sorted_envp, i);
	print_envp(sorted_envp, true);
	ft_free_ptr(sorted_envp);
}

static void	print_envp(char *envp[], bool for_export)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strchr(envp[i], '=') != NULL)
		{
			if (for_export)
				ft_putstr_fd("export ", 1);
			ft_putstr_fd(envp[i], 1);
			ft_putstr_fd("\n", 1);
		}
		i++;
	}
}