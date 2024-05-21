/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:42:30 by astavrop          #+#    #+#             */
/*   Updated: 2024/05/21 20:21:04 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"
#include <stdio.h> /* DELETE */

static char	*connect_kv(char *key, char *value);
static char	**split_kv(char *entry);

char	**generate_envpv(t_kv envp_ht[TABLE_SIZE])
{
	char	**envpv;
	int		envp_size;
	char	**envp_keys;
	int		i;

	envp_size = (int) ht_len(envp_ht);
	envp_keys = ht_get_keys(envp_ht);
	if (!envp_keys)
		return (NULL);
	envpv = ft_malloc(NULL, sizeof(*envpv) * (envp_size + 1));
	if (!envpv)
		return (NULL);
	i = 0;
	while (i < envp_size)
	{
		envpv[i] = connect_kv(envp_keys[i], ht_get(envp_ht, envp_keys[i]));
		i++;
	}
	return (envpv);
}

void	generate_envp_ht(t_kv envp_ht[TABLE_SIZE], char **envpv)
{
	int		i;
	char	**kv;

	i = 0;
	while (envpv[i])
	{
		kv = split_kv(envpv[i]);
		if (!kv || !kv[KEY] || !kv[VALUE])
			continue ;
		ht_set(envp_ht, kv[KEY], kv[VALUE]);
		i++;
	}
}

static char	*connect_kv(char *key, char *value)
{
	int		i;
	int		total_len;
	int		key_len;
	char	*entry;

	total_len = ft_strlen(key) + 1 + ft_strlen(value);
	key_len = ft_strlen(key);
	entry = ft_malloc(NULL, sizeof(char) * (total_len + 1));
	if (!entry)
		return (NULL);
	i = 0;
	while (i < key_len)
	{
		entry[i] = key[i];
		i++;
	}
	entry[i++] = '=';
	while (i < total_len)
	{
		entry[i] = value[i - key_len - 1];
		i++;
	}
	entry[i] = 0;
	return (entry);
}

static char	**split_kv(char *entry)
{
	char	**kv;
	int		i;

	i = 0;
	while (entry[i] && entry[i] != '=')
		i++;
	kv = ft_malloc(NULL, sizeof(*kv) * 3);
	if (!kv)
		return (NULL);
	kv[KEY] = ft_substr(entry, 0, i);
	kv[VALUE] = ft_substr(entry, i + 1, ft_strlen(entry) - i);
	kv[2] = NULL;
	return (kv);
}
