/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 20:08:16 by astavrop          #+#    #+#             */
/*   Updated: 2024/06/09 21:18:42 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"
#include "../../lib/libft/libft.h"

#include <stdbool.h>

int	echo_builtin(t_Command *echo)
{
	int		i;
	bool	new_line;

	if (!echo->args[1])
		return (-1);
	new_line = true;
	i = 1;
	if (ft_strcmp(echo->args[i], "-n") == 0 && i++)
		new_line = false;
	while (echo->args[i + 1])
	{
		ft_putstr_fd(echo->args[i], 1);
		ft_putstr_fd(" ", 1);
		i++;
	}
	ft_putstr_fd(echo->args[i], 1);
	if (new_line)
		ft_putstr_fd("\n", 1);
	return (0);
}
