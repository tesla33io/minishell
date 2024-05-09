/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:57:24 by astavrop          #+#    #+#             */
/*   Updated: 2024/05/09 21:53:41 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft/libft.h"
#include <stdbool.h>
#include <stddef.h>

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

char	**envp_ht_to_str_array(t_kv envp_ht[TABLE_SIZE])
{
	size_t	envp_size;
	int		i;
	char	**envp_str_array;
	char	**keys;

	envp_size = get_hash_table_size(envp_ht);
	keys = get_all_keys(envp_ht);
	i = 0;
	envp_str_array = ft_strarray_alloc(envp_size);
	if (!envp_str_array)
		return (NULL);
	while (i < envp_size)
	{
	}
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
