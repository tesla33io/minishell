/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:29:20 by astavrop          #+#    #+#             */
/*   Updated: 2024/07/02 19:55:02 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

#include <stdio.h> /* TODO: DELETE */

/***************************************/
/* Primitive Garbage Collection System */
/***************************************/

/**
 * Initializes the garbage collector deque.
 *
 * This function sets up the garbage collector by allocating memory for the deque
 * and initializing its fields. If the memory allocation fails, an error message
 * is printed to standard error.
 *
 * Parameters:
 * - gc: Pointer to the deque structure to initialize.
 */
t_deque	*gc_init(t_deque *gc)
{
	gc = gc_malloc(NULL, sizeof(*gc));
	if (!gc && (ft_putendl_fd("\n\nFUCK!\n\n", 2), 1))
		return (NULL);
	gc->head = NULL;
	gc->size = 0;
	return (gc);
}

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
void	*gc_malloc(t_deque *gc, size_t size)
{
	void	*ret;

	ret = malloc(size);
	if (!ret)
		ft_putstr_fd("Error (gc_malloc): memory allocation failed.\n", 2);
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
 *
 * Parameters:
 * - gc: Pointer to the deque structure containing pointers to be freed.
 */
void	gc_free_gc(t_deque *gc)
{
	t_deque_node	*node;

	if (!gc)
		return ;
	while (gc->size > 0)
	{
		node = deque_pop_front(gc);
		if (node->data && printf("[d] :: Free node data\n"))
			free(node->data);
		free(node);
	}
	free(gc);
}
