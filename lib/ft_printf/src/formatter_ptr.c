/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatter_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:15:18 by astavrop          #+#    #+#             */
/*   Updated: 2023/12/17 17:29:45 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdlib.h>

int	ft_putptr_fd(unsigned long ptr, int fd)
{
	char		hex_digit;
	int			remainder;
	int			temp;
	static int	len;

	if (ptr == 0)
	{
		temp = len;
		len = 0;
		return (temp);
	}
	ft_putptr_fd(ptr / 16, fd);
	remainder = ptr % 16;
	if (remainder < 10)
		hex_digit = '0' + remainder;
	else
		hex_digit = 'a' + remainder - 10;
	ft_putchar_fd(hex_digit, fd);
	len++;
	return (len);
}

int	formatter_ptr(void *ptr, int count, int fd)
{
	if (!ptr)
	{
		ft_putstr_fd("(nil)", fd);
		return (5);
	}
	ft_putstr_fd("0x", fd);
	return (count + ft_putptr_fd((unsigned long) ptr, fd) + 2);
}
