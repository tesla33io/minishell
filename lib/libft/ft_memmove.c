/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:29:28 by astavrop          #+#    #+#             */
/*   Updated: 2023/11/16 15:51:19 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Copies 'n' bytes of memory from 'src' to 'dest'. The memory areas may overlap.
 *
 * @param dest Pointer to the destination memory area.
 * @param src  Pointer to the source memory area.
 * @param n    Number of bytes to be copied.
 * @return     Pointer to the destination memory area ('dest').
 *
 * Memory is copied from the 'src' to 'dest' for 'n' bytes. If 'src' and 'dest'
 * memory areas overlap and 'src' is before 'dest' in memory, the copying is
 * performed from end to start to prevent data corruption. Otherwise, the copying
 * proceeds from start to end.
 */

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *) dest;
	s = (const unsigned char *) src;
	if (d == s)
		return (dest);
	if (s < d && d < s + n)
		while (n--)
			d[n] = s[n];
	else
		while (n--)
			*d++ = *s++;
	return (dest);
}
