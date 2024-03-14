/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatter_xX.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:15:18 by astavrop          #+#    #+#             */
/*   Updated: 2023/12/17 17:30:03 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>

int	ft_hexlen(long int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_puthex_fd(unsigned int num, int upper, int fd)
{
	if (num >= 16)
	{
		ft_puthex_fd(num / 16, upper, fd);
		ft_puthex_fd(num % 16, upper, fd);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), fd);
		else
		{
			if (!upper)
				ft_putchar_fd((num - 10 + 'a'), fd);
			if (upper)
				ft_putchar_fd((num - 10 + 'A'), fd);
		}
	}
}

int	formatter_x(unsigned int x, int count, int upper, int fd)
{
	if (x == 0)
	{
		ft_putchar_fd('0', fd);
		return (1);
	}
	ft_puthex_fd(x, upper, fd);
	return (count + ft_hexlen(x));
}
