/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:29:36 by astavrop          #+#    #+#             */
/*   Updated: 2023/11/16 15:31:04 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Concatenates the source string 'src' onto the destination string 'dest' while
 * ensuring that the total concatenated string length does not exceed
 * 'dstsize - 1'.
 *
 * @param dest     Pointer to the destination string where 'src' will be
 *                 concatenated.
 * @param src      Pointer to the source string that will be concatenated onto
 *                 'dest'.
 * @param dstsize  The size of the destination buffer 'dest'.
 * @return         The total length of the string that would have been created
 *                 if enough space
 *                 had been available. If 'dstsize' is 0, returns the length of
 *                 'src' (because 0 + len(src) == len(src)).
 *
 * This function appends 'src' to the end of 'dest' and ensures the resulting
 * string is null-terminated. It calculates the lengths of 'dest' and 'src',
 * checks if 'dstsize' is 0, and calculates the total length of the concatenated
 * string. If there's enough space in 'dest', it appends 'src' to 'dest' and
 * terminates the result with a null-terminator. The function returns the total
 * length of the concatenated string.
 */

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	d_len;
	size_t	s_len;
	size_t	total_len;
	size_t	i;

	d_len = 0;
	s_len = 0;
	while (dest[d_len] && d_len < dstsize)
		d_len++;
	while (src[s_len])
		s_len++;
	if (dstsize == 0)
		return (s_len);
	total_len = d_len + s_len;
	if (d_len < dstsize - 1)
	{
		i = 0;
		while (d_len < dstsize - 1 && src[i] != '\0')
			dest[d_len++] = src[i++];
		dest[d_len] = '\0';
	}
	return (total_len);
}
