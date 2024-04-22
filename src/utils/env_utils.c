/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:57:24 by astavrop          #+#    #+#             */
/*   Updated: 2024/04/21 16:31:38 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft/libft.h"
#include <stdbool.h>

void	free_envp(char *envp[])
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (envp[i])
			ft_free_ptr(envp[i]);
		i++;
	}
}

char	*create_kv_entry(char *key, char *value)
{
	char	*kv;
	int		total_len;
	int		key_len;
	int		i;

	total_len = ft_strlen(key) + 1 + ft_strlen(value);
	key_len = ft_strlen(key) + 1;
	kv = ft_malloc(NULL, sizeof(char) * total_len);
	i = 0;
	while (i < ft_strlen(key))
	{
		kv[i] = key[i];
		i++;
	}
	kv[i++] = '=';
	while (i - key_len < ft_strlen(value))
	{
		kv[i] = value[i - key_len];
		i++;
	}
	kv[i] = 0;
	return (kv);
}

int	envp_keycmp(char *key, char *envp_entry, size_t key_len)
{
	size_t	i;

	i = 0;
	while (i < key_len)
	{
		if (key[i] != envp_entry[i])
			return (key[i] - envp_entry[i]);
		i++;
	}
	if (envp_entry[i] == '=')
		return (0);
	else
		return (-1);
}

bool	envp_contains(char *key, char *envp[])
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (envp_keycmp(key, envp[i], ft_strlen(key)) == 0)
			return (true);
		i++;
	}
	return (false);
}
