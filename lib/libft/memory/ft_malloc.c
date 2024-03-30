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

/***************************************/
/* Primitive Garbage Collection System */
/***************************************/

/* 
 * Custom memory allocation function that saves a pointer to the allocated
 * memory and handles allocation failures gracefully.
 *
 * Parameters:
 * - gc: Pointer to the deque structure where allocated pointers are stored.
 * - size: Size of memory to allocate.
 *
 * Returns:
 * - A pointer to the allocated memory.
 */
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

/* 
 * Wrapper function for freeing a pointer and setting it to NULL
 * to avoid double freeing.
 * Additionally, it handles NULL pointers gracefully.
 *
 * Parameters:
 * - ptr: Address of the pointer to be freed.
 */
void	ft_free_ptr(void *ptr)
{
	void	**ref;

	if (!ptr)
		return ;
	ref = (void **)&ptr;
	if (*ref)
	{
		free(ptr);
		*ref = NULL;
	}
}

/* 
 * Frees every pointer stored in the given deque structure
 * along with the deque itself.
 * This function assumes that the data stored in the deque are pointers
 * to dynamically allocated memory.
 *
 * Parameters:
 * - gc: Pointer to the deque structure containing pointers to be freed.
 */
void	ft_free_gc(t_deque *gc)
{
	t_deque_node	*node;

	if (!gc)
		return ;
	while (gc->size > 0)
	{
		node = deque_pop_front(gc);
		if (node->data)
			free(node->data);
		free(node);
	}
	free(gc);
}
