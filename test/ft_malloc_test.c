/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:54:24 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/14 15:55:37 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/libft.h"
#include <stdlib.h>

int	test_ft_malloc(void)
{
	char		*str1;
	char		*str2;
	t_deque		*allocated;

	allocated = malloc(sizeof(t_deque));
	allocated->head = NULL;
	allocated->size = 0;
	str1 = ft_malloc(allocated, sizeof(char) * 10);
	str2 = ft_malloc(allocated, sizeof(char) * 10);
	str1[10] = 0;
	str2[10] = 0;
}

