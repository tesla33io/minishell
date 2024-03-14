/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_emplace_front.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:49:17 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/17 19:55:53 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	deque_emplace_front(t_deque *deque, t_deque_type data)
{
	t_deque_node	*new;

	if (deque->head)
	{
		new = malloc(sizeof(t_deque_node));
		if (!new)
			return ;
		new->data = data;
		new->next = deque->head;
		new->prev = deque->head->prev;
		deque->head->prev->next = new;
		deque->head->prev = new;
		deque->head = new;
	}
	else
	{
		deque->head = malloc(sizeof(t_deque_node));
		if (!deque->head)
			return ;
		deque->head->data = data;
		deque->head->next = deque->head;
		deque->head->prev = deque->head;
	}
	deque->size += 1;
}
