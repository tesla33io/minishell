/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_pop_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 20:22:36 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/02 18:01:00 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_deque_node	*deque_pop_front(t_deque *deque)
{
	t_deque_node	*prev;
	t_deque_node	*head;
	t_deque_node	*next;

	head = deque->head;
	if (!head)
		return (NULL);
	prev = head->prev;
	next = head->next;
	if (head == head->next)
		deque->head = NULL;
	else
	{
		deque->head = next;
		next->prev = prev;
		prev->next = next;
	}
	head->next = NULL;
	head->prev = NULL;
	deque->size -= 1;
	return (head);
}
