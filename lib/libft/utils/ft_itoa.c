/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:24:21 by astavrop          #+#    #+#             */
/*   Updated: 2023/11/23 23:51:39 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_digits(long n)
{
	int	count;

	if (n == 0)
		return (1);
	if (n < 0)
		n *= -1;
	count = 0;
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static void	fill_string(char *str, long n, int digits)
{
	int	sign;

	sign = 1;
	if (n < 0)
	{
		sign = -1;
		n = n * -1;
	}
	str += digits;
	*str = '\0';
	while (digits > 0)
	{
		str--;
		if (n == 0 && sign == -1)
			*str = '-';
		else
		{
			*str = (n % 10) + '0';
			n /= 10;
		}
		digits--;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		digits;
	long	nbr;

	nbr = (long) n;
	digits = count_digits(nbr);
	if (nbr < 0)
		digits += 1;
	str = (char *)malloc((digits + 1) * sizeof(char));
	if (!str)
		return (NULL);
	fill_string(str, nbr, digits);
	return (str);
}
