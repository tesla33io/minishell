/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:40:08 by astavrop          #+#    #+#             */
/*   Updated: 2024/05/07 21:51:42 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft/libft.h"
#include "../../include/executor.h"
#include "../../include/builtins.h"

#include <stdlib.h>
#include <stdbool.h>

static void	print_envp(char **keys, t_kv envp_ht[TABLE_SIZE], bool for_export);

void	ft_env(t_SimpleCommand *cmd)
{
	if (!cmd->envp)
		ft_putendl_fd("env: no environment variables", 2);
	else
		// print_envp(, false);
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

void	ft_envdup(t_kv envp_ht[ENVP_HT_SIZE], char *envp[])
{
	char	**kv;
	int		i;

	i = 0;
	while (envp[i] != NULL)
		i++;
	i = -1;
	while (envp[++i] != NULL)
	{
		kv = ft_split_name_value(envp[i]);
		ht_set(envp_ht, kv[0], kv[1]);
	}
}

void	ft_env_sorted(t_kv envp_ht[TABLE_SIZE])
{
	char			**sorted_keys;
	unsigned int	i;

	i = 0;
	sorted_keys = get_all_keys(envp_ht);
	ft_strquicksort((const char **) sorted_keys, i);
	print_envp(sorted_keys, envp_ht, true);
}

static void	print_envp(char **keys, t_kv envp_ht[TABLE_SIZE], bool for_export)
{
	int	i;

	i = 0;
	while (keys[i] != NULL)
	{
		if (for_export)
			ft_putstr_fd("export ", 1);
		ft_putstr_fd(keys[i], 1);
		ft_putstr_fd("=", 1);
		ft_putstr_fd(ht_get(envp_ht, keys[i]), 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
}
