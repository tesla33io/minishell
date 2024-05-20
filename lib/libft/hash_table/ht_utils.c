/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:40:32 by astavrop          #+#    #+#             */
/*   Updated: 2024/05/20 19:51:37 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

#include <stdlib.h>

void	ht_copy(t_kv src_ht[TABLE_SIZE], t_kv dest_ht[TABLE_SIZE])
{
	char	**keys;
	int		i;

	keys = ht_get_keys(src_ht);
	i = -1;
	while (keys[++i] != NULL)
		ht_set(dest_ht, keys[i], ft_strdup(ht_get(src_ht, keys[i])));
	ft_strarray_free(keys);
}

size_t	ht_len(t_kv ht[TABLE_SIZE])
{
	size_t		count;
	int			i;
	struct s_kv	*next;

	count = 0;
	i = -1;
	while (++i < TABLE_SIZE)
	{
		if (ht[i].k == NULL)
			continue ;
		count++;
		next = ht[i].n;
		while (next)
		{
			count++;
			next = next->n;
		}
	}
	return (count);
}

char	**ht_get_keys(t_kv ht[TABLE_SIZE])
{
	char		**keys_arr;
	size_t		ht_size;
	int			i;
	int			j;
	struct s_kv	*next;

	ht_size = ht_len(ht);
	keys_arr = ft_malloc(NULL, sizeof(*keys_arr) * (ht_size + 1));
	i = 0;
	j = 0;
	while (i < TABLE_SIZE)
	{
		if (ht[i].k != NULL)
			keys_arr[j++] = ht[i].k;
		next = ht[i].n;
		while (next)
		{
			keys_arr[j++] = next->k;
			next = next->n;
		}
		i++;
	}
	keys_arr[j] = NULL;
	return (keys_arr);
}

void	ht_clear(t_kv ht[TABLE_SIZE])
{
	int	i;

	i = 0;
	while (i < TABLE_SIZE)
	{
		ht[i].k = NULL;
		ht[i].v = NULL;
		ht[i].n = NULL;
		i++;
	}
}
