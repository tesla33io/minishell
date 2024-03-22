/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <htam@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:13:07 by htam              #+#    #+#             */
/*   Updated: 2024/02/03 18:21:03 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libunit.h"

void	free_list(t_unit_test *head)
{
	t_unit_test	*temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

void	free_exit(t_unit_test *head, int status)
{
	free_list(head);
	exit(status);
}
