/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:40:08 by astavrop          #+#    #+#             */
/*   Updated: 2024/04/08 20:15:05 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft/libft.h"

#include <stdlib.h>

void	ft_env(char *envp[])
{
	int	i;

	if (!envp)
		ft_putendl_fd("env: no environment variables", 2);
	else
	{
		i = 0;
		while (envp[i] != NULL)
			ft_putendl_fd(envp[i++], 1);
	}
}
