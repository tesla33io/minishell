/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_pop_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 20:22:37 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/17 20:43:30 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_deque_node	*deque_pop_back(t_deque *deque)
{
	t_deque_node	*head;
	t_deque_node	*prev;
	t_deque_node	*prev_prev;

	head = deque->head;
	if (!head)
		return (NULL);
	prev = deque->head->prev;
	prev_prev = prev->prev;
	if (head == head->next)
		deque->head = NULL;
	else
	{
		deque->head->prev = prev_prev;
		prev_prev->next = deque->head;
	}
	prev->next = NULL;
	prev->prev = NULL;
	deque->size -= 1;
	return (prev);
}
