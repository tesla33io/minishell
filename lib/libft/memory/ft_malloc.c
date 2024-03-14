/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:29:20 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/14 15:29:23 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

void	*ft_malloc(t_deque *allocated, size_t size)
{
	void	*ret;

	ret = malloc(size);
	if (!ret)
		ft_putstr_fd("Error: memory allocation failed.", 2);
	deque_emplace_back(allocated, ret);
	return (ret);
}

void	free
