/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_push_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 20:21:23 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/22 21:14:28 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	deque_push_back(t_deque *deque, t_deque_node *node)
{
	if (deque->head)
	{
		node->next = deque->head;
		node->prev = deque->head->prev;
		deque->head->prev->next = node;
		deque->head->prev = node;
	}
	else
	{
		deque->head = node;
		deque->head->next = deque->head;
		deque->head->prev = deque->head;
	}
	deque->size += 1;
}
