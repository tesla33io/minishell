/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:40:32 by astavrop          #+#    #+#             */
/*   Updated: 2024/05/07 19:14:08 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "../libft.h"

size_t	get_hash_table_size(t_kv ht[TABLE_SIZE])
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

char	**get_all_keys(t_kv ht[TABLE_SIZE])
{
	char		**keys_arr;
	size_t		ht_size;
	int			i;
	int			j;
	struct s_kv	*next;

	ht_size = get_hash_table_size(ht);
	keys_arr = ft_malloc(NULL, sizeof(*keys_arr) * (ht_size + 1));
	i = 0;
	j = 0;
	while (i < TABLE_SIZE)
	{
		if (ht[i].k != NULL)
			keys_arr[j++] = ht[i].k;
		next = ht[i].n;
		while (next)
			keys_arr[j++] = next->k;
		i++;
	}
	return (keys_arr);
}

void	clear_hash_table(t_kv ht[TABLE_SIZE])
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
