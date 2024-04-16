/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:40:37 by astavrop          #+#    #+#             */
/*   Updated: 2024/04/16 21:11:53 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft/libft.h"

static char	**realloc_envp(char *envp[], char *new_kv[2]);

void	ft_export(char *name, char *value, char **envp[])
{
	*(envp) = realloc_envp(*envp, (char *[2]){name, value});
}

static char	*create_kv_entry(char *name, char *value)
{
	char	*kv;

	kv = ft_malloc(NULL, sizeof(char) * (ft_strlen(name)
				+ ft_strlen(value) + 1));
	kv = ft_strjoin(name, "=");
	kv = ft_strjoin(kv, value);
	return (kv);
}

static char	**realloc_envp(char *envp[], char *new_kv[2])
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
	new_envp = ft_malloc(NULL, (size_t) sizeof(char *) * (i + 1));
	i = 0;
	while (envp[i + 1] != NULL)
	{
		new_envp[i] = ft_strdup(envp[i]);
		i++;
	}
	new_envp[i + 1] = create_kv_entry(new_kv[0], new_kv[1]);
	new_envp[i + 2] = envp[i];
	new_envp[i + 3] = NULL;
	return (new_envp);
}
