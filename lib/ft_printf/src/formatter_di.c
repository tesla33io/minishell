/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatter_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:15:18 by astavrop          #+#    #+#             */
/*   Updated: 2023/12/08 16:18:52 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>

int	numlen(long int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
		n = -n;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

int	formatter_di(int n, int count, int fd)
{
	int	len;

	len = numlen((long int) n);
	if (n < 0)
		len++;
	ft_putnbr_fd(n, fd);
	return (count + len);
}
