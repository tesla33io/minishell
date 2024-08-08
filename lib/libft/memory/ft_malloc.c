/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:29:20 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/08 16:56:05 by astavrop         ###   ########.fr       */
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
t_list	**gc_get_storage(int i)
{
	static t_list	*gc[10] = {NULL};

	if (i < 0 || i > 9)
		i = gc_set_storage('g');
	if (!gc[i])
	{
		gc[i] = ft_calloc(1, sizeof(*gc[i]));
		gc[i]->content = NULL;
		gc[i]->next = NULL;
	}
	return (&gc[i]);
}

int	gc_set_storage(int flag)
{
	static int	storage;

	if (flag == 'g')
		return (storage);
	storage = flag;
	return (storage);
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
	t_list	**gc;

	ret = malloc(size);
	if (!ret)
		ft_putstr_fd("Error (gc_malloc): memory allocation failed.\n", 2);
	gc = gc_get_storage(-1);
	if (!gc || !*gc)
		return (NULL);
	new_node = ft_lstnew(ret);
	if (!new_node)
		return (NULL);
	ft_memset(ret, 0, size);
	ft_lstadd_back(gc, new_node);
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
void gc_free_ptr(void **ptr)
{
    if (ptr == NULL || *ptr == NULL)
        return ;
    free(*ptr);
    *ptr = NULL;
}

/* 
 * Frees every pointer stored in the given deque structure
 * along with the linked list itself.
 * This function assumes that the data stored in the deque are pointers
 * to dynamically allocated memory.
 */
void	gc_free_gc(int flag)
{
	t_list		*node;
	t_list		*tmp;
	t_list		**gc;

	gc = gc_get_storage(flag);
	if (gc == NULL || *gc == NULL)
		return ;
	node = *gc;
	while (node->next)
	{
		if (node->content)
			gc_free_ptr((void **) &node->content);
		tmp = node;
		node = node->next;
		gc_free_ptr((void **) &tmp);
	}
	gc_free_ptr((void **) &node->content);
	gc_free_ptr((void **) &node);
	*gc = NULL;
}
