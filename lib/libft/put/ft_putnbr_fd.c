/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:33:24 by astavrop          #+#    #+#             */
/*   Updated: 2024/01/15 17:17:38 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Outputs an integer 'n' to the specified file descriptor 'fd'.
 *
 * @param n  The integer to be output.
 * @param fd The file descriptor where the integer will be output.
 *
 * Outputs the integer 'n' to the specified file descriptor 'fd'.
 * If 'n' is negative, the '-' sign is output first.
 * The function utilizes recursion to output individual digits of the integer.
 * For positive integers, it outputs each digit character by character.
 * If number is less than 10, that is the Base Case for recursion.
 */

void	ft_putnbr_lft_fd(int n, int fd)
{
	long	nbr;

	nbr = (long) n;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr *= -1;
	}
	if (nbr >= 10)
	{
		ft_putnbr_lft_fd(nbr / 10, fd);
		ft_putnbr_lft_fd(nbr % 10, fd);
	}
	else
		ft_putchar_fd(nbr + 48, fd);
}
