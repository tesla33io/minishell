/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 20:08:16 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/08 21:03:22 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"
#include "../../lib/libft/libft.h"

#include <stdbool.h>

int	echo_builtin(t_Command *echo)
{
	int		i;
	bool	new_line;

	new_line = true;
	i = 1;
	if (echo->args[i] && echo->args[i][0]
		&& ft_strcmp("-n", echo->args[i]) == 0 && i++)
		new_line = false;
	while (echo->args && echo->args[i] && echo->args[i + 1])
	{
		if (ft_strncmp(echo->args[i], "", 1) == 0 && i++)
			continue ;
		ft_putstr_fd(echo->args[i], 1);
		ft_putstr_fd(" ", 1);
		i++;
	}
	if (echo->args && echo->args[i])
		ft_putstr_fd(echo->args[i], 1);
	if (new_line)
		ft_putstr_fd("\n", 1);
	return (0);
}
