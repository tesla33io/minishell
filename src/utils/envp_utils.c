/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:42:30 by astavrop          #+#    #+#             */
/*   Updated: 2024/07/22 19:24:18 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"
#include "../../include/colors.h"

#include <stddef.h>
#include <stdio.h> /* DELETE */
#include <string.h>
#include <unistd.h>

char	*ft_getenv(char **envp, char *name)
{
	char	*var;
	int		i;

	i = 0;
	var = NULL;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], name, ft_strlen(name)) == 0)
		{
			var = envp[i] + 5;
			break ;
		}
		i++;
	}
	return (var);
}

char	*find_executable_on_path(char *path, char *bin_name)
{
	char	**path_entries;
	char	*tmp_bin_name;
	int		i;

	path_entries = ft_split(path, ':');
	if (!path_entries)
		return (NULL);
	i = 0;
	while (path_entries[i] != NULL)
	{
		tmp_bin_name = ft_path_join(path_entries[i], bin_name);
		if (!bin_name)
			return (printf("ft_path_join failed.\n"), NULL);
		if (access(tmp_bin_name, F_OK) == 0 && access(tmp_bin_name, X_OK) == 0)
		{
			ft_strarray_free(path_entries);
			return (tmp_bin_name);
		}
		else
			gc_free_ptr((void **) &tmp_bin_name);
		i++;
	}
	return (printf("[REPLACE] %s: programm not found\n", bin_name), NULL);
}

/*
static char	*connect_kv(char *key, char *value);
static char	**split_kv(char *entry);

char	**generate_envpv(t_kv envp_ht[TABLE_SIZE])
{
	char	**envpv;
	int		envp_size;
	char	**envp_keys;
	int		i;
	(void)size;

	printf("%p (generat_envpv)\n", (void *) &envp_ht);
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
		printf("key: %s\n", envp_keys[i]);
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
*/
