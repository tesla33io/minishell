/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:40:37 by astavrop          #+#    #+#             */
/*   Updated: 2024/05/10 18:45:33 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft/libft.h"
#include "../../include/builtins.h"
#include <stdio.h>
#include <stdlib.h>

#define KEY 0
#define VALUE 1

static int	set_variable(char *kv_pair, t_kv envp_ht[TABLE_SIZE]);

void	ft_export(t_SimpleCommand *cmd)
{
	int	i;

	i = 1;
	if (!cmd->args[i])
	{
		// ft_env_sorted(cmd->envp);
		return ;
	}
	while (cmd->args[i])
	{
		if (ft_strchr(cmd->args[i], '=') != NULL)
		{
			if (set_variable(cmd->args[i], cmd->envp_ht) != 0)
				ft_putendl_fd("ft_export: can't split input into key and value\n", 2);
		}
		i++;
	}
}

static int	set_variable(char *kv_pair, t_kv envp_ht[TABLE_SIZE])
{
	char	**kv;

	kv = ft_split_name_value(kv_pair);
	if (!kv || !kv[KEY] || !kv[VALUE])
		return (1);
	ht_set(envp_ht, kv[KEY], kv[VALUE]);
	/*
	if (envp_contains(kv[KEY], *envp))
		*(envp) = change_value(*envp, (char *[2]){kv[KEY], kv[VALUE]});
	else
		*(envp) = realloc_envp(*envp, (char *[2]){kv[KEY], kv[VALUE]});
	*/
	return (0);
}

/*static char	**change_value(char *envp[], char *kv[2])
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (envp_keycmp(kv[0], envp[i], ft_strlen(kv[0])) == 0)
		{
			ft_free_ptr(envp[i]);
			envp[i] = create_kv_entry(kv[0], kv[1]);
			break ;
		}
		i++;
	}
	return (envp);
}*/

/*static char	**realloc_envp(char *envp[], char *new_kv[2])
{
	char	**new_envp;
	int		i;

	if (!new_kv[0] || !new_kv[1])
	{
		ft_putendl_fd("Error: realloc_envp failed", 2);
		return (NULL);
	}
	i = -1;
	while (envp[++i])
		;
	new_envp = ft_malloc(NULL, (size_t) sizeof(char *) * (i + 2));
	i = 0;
	while (envp[i] != NULL)
	{
		new_envp[i] = ft_strdup(envp[i]);
		i++;
	}
	new_envp[i] = create_kv_entry(new_kv[0], new_kv[1]);
	new_envp[i + 1] = envp[i];
	new_envp[i + 2] = NULL;
	return (new_envp);
}*/
