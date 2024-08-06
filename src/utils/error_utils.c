/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:30:56 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/05 20:45:15 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../lib/libft/libft.h"

void	*ret_null(char *msg, char *func, int line)
{
	ft_putstr_fd("[", 2);
	ft_putstr_fd(func, 2);
	ft_putstr_fd(":", 2);
	ft_putnbr_lft_fd(line, 2);
	ft_putstr_fd("] - ", 2);
	ft_putendl_fd(msg, 2);
	return (NULL);
}

int	ret_int(char *msg, char *func, int line, int code)
{
	ft_putstr_fd("[", 2);
	ft_putstr_fd(func, 2);
	ft_putstr_fd(":", 2);
	ft_putnbr_lft_fd(line, 2);
	ft_putstr_fd("] - ", 2);
	ft_putendl_fd(msg, 2);
	return (code);
}

int	builtin_failed(char *msg, char *func, int code)
{
	ft_putstr_fd(func, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(msg, 2);
	return (code);
}
