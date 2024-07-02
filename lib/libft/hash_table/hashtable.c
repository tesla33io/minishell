/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:37:08 by astavrop          #+#    #+#             */
/*   Updated: 2024/07/02 17:26:53 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "../libft.h"

/* elf_hash_32 */
/* https://github.com/cubernetes/42_rush_hotrace/tree/main */
unsigned int	hash(char *key)
{
	unsigned int	hash;
	unsigned int	g;
	unsigned char	*str;

	hash = 0;
	g = 0;
	str = (unsigned char *)key;
	while (*str)
	{
		hash = (hash << 4) + *str++;
		g = hash & 0xf0000000;
		if (g)
			hash ^= g >> 24;
		hash &= ~g;
	}
	return (hash);
}

void	ht_set(t_kv ht[TABLE_SIZE], char *key, void *value)
{
	int		idx;
	t_kv	*new_kv;

	idx = hash(key) % TABLE_SIZE;
	if (!ht[idx].k)
	{
		ht[idx].k = key;
		ht[idx].v = value;
		ht[idx].n = NULL;
	}
	else
	{
		new_kv = gc_malloc(NULL, sizeof(*new_kv));
		new_kv->k = key;
		new_kv->v = value;
		new_kv->n = ht[idx].n;
		ht[idx].n = new_kv;
	}
}

char	*ht_get(t_kv ht[TABLE_SIZE], char *key)
{
	t_kv	*kv;

	kv = &ht[hash(key) % TABLE_SIZE];
	while (kv && kv->k && ft_strncmp(kv->k, key, ft_strlen(key)))
		kv = kv->n;
	if (kv && kv->k)
		return (kv->v);
	return (NULL);
}

t_kv	*ht_init(void)
{
	t_kv	*ht;

	ht = gc_malloc(NULL, sizeof(*ht) * TABLE_SIZE);
	return (ht);
}

void	ht_destroy(t_kv ht[TABLE_SIZE])
{
	int		i;
	t_kv	*prev;
	t_kv	*kv;
	int		j;

	i = -1;
	while (++i < TABLE_SIZE)
	{
		kv = &ht[i];
		if (kv->k == NULL)
			continue ;
		j = 0;
		while (kv)
		{
			gc_free_ptr(kv->k);
			// gc_free_ptr(kv->v);
			prev = kv;
			kv = kv->n;
			if (j > 0)
				gc_free_ptr(prev);
			++j;
		}
	}
}
