/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:25:15 by astavrop          #+#    #+#             */
/*   Updated: 2024/07/23 19:54:57 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list	*end;

	if (!lst || !lst[0] || !new_node)
		return ;
	end = ft_lstlast((*lst));
	if (end)
		end->next = new_node;
	else
		(*lst) = new_node;
}
