/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:29:20 by astavrop          #+#    #+#             */
/*   Updated: 2024/07/09 19:34:21 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

#include <stdio.h> /* TODO: DELETE */

/***************************************/
/* Primitive Garbage Collection System */
/***************************************/

/**
 * Retrieves the static garbage collector storage.
 * 
 * This function returns a pointer to a static `t_deque` structure that acts
 * as the garbage collector (GC) storage. If the storage has not been 
 * initialized yet, it initializes it.
 *
 * Returns:
 * - A pointer to the static `t_deque` storage.
 */
t_deque	*gc_get_storage(void)
{
	static t_deque	*gc = NULL;

	if (!gc)
		gc = malloc(sizeof(*gc));
	return (gc);
}

/* 
 * Custom memory allocation function that saves a pointer to the allocated
 * memory and handles allocation failures gracefully.
 *
 * Parameters:
 * - size: Size of memory to allocate.
 *
 * Returns:
 * - A pointer to the allocated memory.
 */
void	*gc_malloc(size_t size)
{
	void			*ret;

	ret = malloc(size);
	if (!ret)
		ft_putstr_fd("Error (gc_malloc): memory allocation failed.\n", 2);
	deque_emplace_back(gc_get_storage(), ret);
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
void	gc_free_ptr(void *ptr)
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
 */
void	gc_free_gc(void)
{
	t_deque_node	*node;
	t_deque			*gc;

	gc = gc_get_storage();
	while (gc->size > 0)
	{
		node = deque_pop_front(gc);
		if (node->data)
			free(node->data);
		free(node);
	}
	free(gc);
}
