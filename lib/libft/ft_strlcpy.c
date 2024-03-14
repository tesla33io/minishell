/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:29:39 by astavrop          #+#    #+#             */
/*   Updated: 2023/11/16 15:31:09 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Copies the source string 'src' into the destination string 'dest' while
 * ensuring null-termination and limiting the copy length to 'dstsize - 1'
 * characters (to leave space for the null-terminator).
 *
 * @param dest     Pointer to the destination string where 'src' will be copied.
 * @param src      Pointer to the source string that will be copied into 'dest'.
 * @param dstsize  The size of the destination buffer 'dest'.
 * @return         The length of the source string 'src'.
 *
 * This function copies characters from 'src' to 'dest' until either
 * 'dstsize - 1' characters have been copied or a null-terminator is encountered
 * in 'src'. If 'dstsize' is greater than 0, it ensures null-termination of the
 * resulting string in 'dest'. The function then calculates and returns the
 * length of 'src'.
 */

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	len;

	len = 0;
	if (dstsize > 0)
	{
		while (*(src + len) && --dstsize)
			*dest++ = *(src + len++);
		*dest = '\0';
	}
	while (*(src + len))
		++len;
	return (len);
}
