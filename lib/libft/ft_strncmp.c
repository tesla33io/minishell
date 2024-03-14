/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:29:43 by astavrop          #+#    #+#             */
/*   Updated: 2023/11/16 15:31:20 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Compares 'n' bytes of two strings.
 *
 * @param s1 Pointer to the first string.
 * @param s2 Pointer to the second string.
 * @param n Number of bytes to compare.
 * @return An integer representing the comparison result:
 * - 0 > if the first differing byte in s1 is less than that in s2.
 * - 0 < if the first differing byte in s1 is greater than that in s2.
 * - 0 = if the first 'n' bytes of s1 and s2 are equal.
 *
 * Compares 'n' bytes of the strings pointed to by 's1' and 's2'. If 'n' reaches
 * zero or a mismatch is found, the function returns the difference between the
 * respective byte values.
 */

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;

	str1 = (const unsigned char *) s1;
	str2 = (const unsigned char *) s2;
	if (n == 0)
		return (0);
	while (*str1 && *str2 && *str1 == *str2 && --n)
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
