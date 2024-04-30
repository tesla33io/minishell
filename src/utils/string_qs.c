/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_qs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 21:23:47 by astavrop          #+#    #+#             */
/*   Updated: 2024/04/30 21:56:45 by astavrop         ###   ########.fr       */
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
	unsigned int piv;

	if (length <= 1) 
		return ;
	i = 0;
	piv = 0;
	while (i < length)
	{
		// if curr str < pivot str, move curr into lower array and  lower++(pvt)
		if (ft_strncmp(arr[i], arr[length - 1], ft_strlen(arr[i]) < 0)) //use string in last index as pivot
			swap(arr + i, arr + piv++);
		i++;
	}
	//move pivot to "middle"
	swap(arr + piv, arr + length - 1);
	//recursively sort upper and lower
	ft_strquicksort(arr, piv++); //set length to current pvt and increase for next call
	ft_strquicksort(arr + piv, length - piv);
}
