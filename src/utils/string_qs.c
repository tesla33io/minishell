/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_qs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 21:23:47 by astavrop          #+#    #+#             */
/*   Updated: 2024/04/30 22:03:04 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft/libft.h"

/* Swaps position of strings in array (char**) */
static void	swap(const char **a, const char **b)
{
	const char *temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_strquicksort(char const *arr[], unsigned int length)
{
	unsigned int i;
	unsigned int j;

	if (length <= 1) 
		return ;
	i = 0;
	while (i < length)
	{
		j = 0;
		while (j < length - i - 1)
		{
			if (ft_strncmp(arr[j],
						arr[j + 1],
						ft_strlen(arr[j])) > 0)
				swap(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
}
