/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:29:20 by astavrop          #+#    #+#             */
/*   Updated: 2024/07/09 20:08:52 by astavrop         ###   ########.fr       */
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
 * This function returns a pointer to a static `t_list` structure that acts
 * as the garbage collector (GC) storage. If the storage has not been 
 * initialized yet, it initializes it.
 *
 * Returns:
 * - A pointer to the static `t_list` storage.
 */
t_list	**gc_get_storage(void)
{
	static t_list	*gc = NULL;

	if (!gc)
	{
		gc = malloc(sizeof(*gc));
		gc->content = NULL;
		gc->next = NULL;
	}
	return (&gc);
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
	void	*ret;
	t_list	*new_node;

	ret = malloc(size);
	if (!ret)
		ft_putstr_fd("Error (gc_malloc): memory allocation failed.\n", 2);
	new_node = ft_lstnew(ret);
	ft_lstadd_back(gc_get_storage(), new_node);
	printf("Debug:: new ptr added: %p\n", gc_get_storage());
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
	t_list		*node;
	t_list		*tmp;
	t_list		**gc;

	gc = gc_get_storage();
	node = *gc;
	while (node->next)
	{
		if (node->content)
			free(node->content);
		tmp = node;
		node = node->next;
		free(tmp);
	}
	free(node->content);
	free(node);
}
