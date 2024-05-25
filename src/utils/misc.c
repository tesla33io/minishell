/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 20:13:31 by astavrop          #+#    #+#             */
/*   Updated: 2024/05/25 17:14:45 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"

#include <stdio.h>

char	*ft_path_join(char *path1, char *path2)
{
	char	*new_path;

	if (path1[ft_strlen(path1) - 1] != '/')
	{
		path1 = ft_strjoin(path1, "/");
		if (!path1)
			return (NULL);
	}
	new_path = ft_strjoin(path1, path2);
	if (!new_path)
		return (NULL);
	return (new_path);
}

void	print_strarray(char **arr)
{
	for (int i = 0; arr[i] != NULL; ++i)
	{
		printf("[%s] > ", arr[i]);
	}
	printf("[NULL]\n");
}

void	print_hashtable(t_kv ht[TABLE_SIZE])
{
	t_kv	*next = NULL;
	for (int i = 0; i < TABLE_SIZE; ++i)
	{
		if (ht[i].k != NULL && ht[i].v != NULL)
		{
			printf("{K=%s; V=%s}->", ht[i].k, (char *) ht[i].v);
			if (ht[i].n != NULL)
			{
				next = ht[i].n;
				while (next != NULL)
				{
					printf("{K=%s; V=%s}->", next->k, (char *) next->v);
					next = next->n;
				}
			}
		}
	}
	printf("{end}\n");
}
