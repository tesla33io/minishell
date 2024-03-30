/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:27:49 by astavrop          #+#    #+#             */
/*   Updated: 2023/11/16 15:30:23 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Compares 'n' bytes of memory between two memory areas pointed to by 's1' and
 * 's2'.
 *
 * @param s1 Pointer to the first memory area.
 * @param s2 Pointer to the second memory area.
 * @param n  Number of bytes to compare.
 * @return   An integer less than, equal to, or greater than zero if the 'n'
 *           bytes of memory pointed to by 's1' are found, respectively, to be
 *           less than, equal to, or greater than the 'n' bytes pointed to by
 *           's2'.
 *
 * This function compares 'n' bytes of memory between the 's1' and 's2' pointers.
 * It iterates through both memory areas and returns zero if they are identical.
 * If a difference is found, it returns the difference between the 1st differing
 * pair of bytes (treated as unsigned char).
 */

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	while (n > 0)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
		n--;
	}
	return (0);
}
