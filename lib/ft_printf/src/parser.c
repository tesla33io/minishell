/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:30:36 by astavrop          #+#    #+#             */
/*   Updated: 2023/12/17 17:24:16 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>

int	formatter_other(const char *s, int fd)
{
	ft_putchar_fd(*s, fd);
	return (1);
}

int	process_formatter(const char **s, va_list arg, int fd)
{
	int	c;

	c = 0;
	if (*(*s))
	{
		(*s)++;
		if (*(*s) == 'i' || *(*s) == 'd')
			c += formatter_di((int) va_arg(arg, int), c, fd);
		else if (*(*s) == 'u')
			c += formatter_u((unsigned int) va_arg(arg, unsigned int), c, fd);
		else if (*(*s) == 'c')
			c += formatter_c((char) va_arg(arg, int), c, fd);
		else if (*(*s) == 's')
			c += formatter_s((char *) va_arg(arg, char *), c, fd);
		else if (*(*s) == 'p')
			c += formatter_ptr((void *) va_arg(arg, void *), c, fd);
		else if (*(*s) == 'x')
			c += formatter_x((long int) va_arg(arg, long int), c, 0, fd);
		else if (*(*s) == 'X')
			c += formatter_x((long int) va_arg(arg, long int), c, 1, fd);
		else
			c += formatter_other(*(s), fd);
		(*s)++;
	}
	return (c);
}

int	print(int fd, const char *s, va_list arg)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s != '%' && *s)
		{
			ft_putchar_fd(*s, fd);
			s++;
			count++;
		}
		count += process_formatter(&s, arg, fd);
	}
	return (count);
}
