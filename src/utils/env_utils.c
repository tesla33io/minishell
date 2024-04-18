/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:57:24 by astavrop          #+#    #+#             */
/*   Updated: 2024/04/18 17:02:05 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft/libft.h"

void	free_envp(char *envp[])
{
	int	i;

	i = 0;
	while (envp[i])
	{
		ft_free_ptr(envp[i]);
		i++;
	}
}
