/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatter_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:15:18 by astavrop          #+#    #+#             */
/*   Updated: 2023/12/07 17:16:46 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>

int	s_null(int fd)
{
	ft_putstr_fd("(null)", fd);
	return (6);
}

int	formatter_s(char *s, int count, int fd)
{
	if (!s)
		return (s_null(fd));
	ft_putstr_fd(s, fd);
	return (count + ft_strlen(s));
}
