/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_push_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 20:05:49 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/07 19:42:34 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	deque_push_front(t_deque *deque, t_deque_node *node)
{
	if (deque->head)
	{
		node->next = deque->head;
		node->prev = deque->head->prev;
		deque->head->prev->next = node;
		deque->head->prev = node;
		deque->head = node;
	}
	else
	{
		deque->head = node;
		deque->head->next = deque->head;
		deque->head->prev = deque->head;
	}
	deque->size += 1;
}
