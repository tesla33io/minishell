/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 20:59:23 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/23 20:59:23 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtins.h"
#include "../../lib/libft/libft.h"
#include "../../lib/ft_printf/includes/ft_printf.h"

#include <stdlib.h>
#include <stdbool.h>

void	ft_echo(int fd, int ac, char **av)
{
	int		i;
	bool	new_line;

	if (!av[0])
		return ;
	new_line = true;
	if (ft_strncmp(av[0], "-n", 2) == 0)
		new_line = false;
	i = -1;
	while (++i < ac)
		ft_printf(fd, "%s", av[i]);
	if (new_line)
		ft_putstr_fd("\n", fd);
}