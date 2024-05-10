/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:57:24 by astavrop          #+#    #+#             */
/*   Updated: 2024/05/10 18:16:30 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft/libft.h"
#include <stdbool.h>
#include <stddef.h>

char	*create_kv_entry(char *key, t_kv envp_ht[TABLE_SIZE])
{
	char	*kv;
	char	*value;
	int		total_len;
	int		key_len;
	int		i;

	value = ht_get(envp_ht, key);
	total_len = ft_strlen(key) + 1 + ft_strlen(value);
	key_len = ft_strlen(key) + 1;
	kv = ft_malloc(NULL, sizeof(char) * total_len);
	i = -1;
	while (++i < ft_strlen(key))
		kv[i] = key[i];
	kv[i] = '=';
	while (++i - key_len < ft_strlen(value))
		kv[i] = value[i - key_len];
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
	envp_str_array = ft_strarray_alloc(envp_size);
	if (!envp_str_array)
		return (NULL);
	i = 0;
	while (i < (int)envp_size)
	{
		envp_str_array[i] = create_kv_entry(keys[i], envp_ht);
		i++;
	}
	envp_str_array[i] = NULL;
	return (envp_str_array);
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
