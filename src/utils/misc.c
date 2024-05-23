/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 20:13:31 by astavrop          #+#    #+#             */
/*   Updated: 2024/05/24 20:59:59 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"

#include <stdio.h>

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
