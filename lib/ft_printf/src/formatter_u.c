/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatter_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:15:18 by astavrop          #+#    #+#             */
/*   Updated: 2023/12/08 16:18:52 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>

int	formatter_u(unsigned int n, int count, int fd)
{
	ft_putnbr_fd((long int) n, fd);
	return (count + numlen((long int) n));
}
