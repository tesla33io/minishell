/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:40:37 by astavrop          #+#    #+#             */
/*   Updated: 2024/04/20 15:03:04 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft/libft.h"
#include "../../include/builtins.h"

static char	**change_value(char *envp[], char *kv[2]);
static char	**realloc_envp(char *envp[], char *new_kv[2]);

void	ft_export(char *name, char *value, char **envp[])
{
	if (envp_contains(name, *envp))
		*(envp) = change_value(*envp, (char *[2]){name, value});
	else
		*(envp) = realloc_envp(*envp, (char *[2]){name, value});
}

static char	**change_value(char *envp[], char *kv[2])
{
	int	i;
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(kv[0], envp[i], ft_strlen(kv[0])) == 0)
			// coming soon...
		i++;
	}
	return (envp);
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
}
