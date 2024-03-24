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

void	*ft_malloc(t_deque *gc, size_t size)
{
	void	*ret;

	ret = malloc(size);
	if (!ret)
		ft_putstr_fd("Error (ft_malloc): memory allocation failed.\n", 2);
	if (gc)
		deque_emplace_back(gc, ret);
	return (ret);
}

void	ft_free_ptr(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	ft_free_gc(t_deque *gc)
{
	t_deque_node	*node;

	while (gc->size > 0)
	{
		node = deque_pop_front(gc);
		if (node->data)
			free(node->data);
		free(node);
	}
	free(gc);
}
