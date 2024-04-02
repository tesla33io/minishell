/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:59:32 by astavrop          #+#    #+#             */
/*   Updated: 2024/04/02 14:05:23 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtins.h"
#include "../../lib/libft/libft.h"

#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

void	ft_cd(const char *path)
{
	int	errnum;

	if (chdir(path) != 0)
	{
		errnum = errno;
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(strerror(errnum), 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd((char *)path, 2);
	}
}
