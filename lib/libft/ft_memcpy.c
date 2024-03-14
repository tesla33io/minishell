/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:29:22 by astavrop          #+#    #+#             */
/*   Updated: 2023/11/16 15:30:42 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Copies 'n' bytes of data from 'src' to 'dest'.
 *
 * @param dest Pointer to the destination buffer where data is copied.
 * @param src Pointer to the source of data to be copied.
 * @param n Number of bytes to copy.
 * @return A pointer to the destination buffer 'dest'.
 *
 * Copies 'n' bytes from the memory area pointed to by 'src' to the memory
 * area pointed to by 'dest'. The memory areas must not overlap.
 * If 'n' is 0 or 'dest' and 'src' are the same, the function returns 'dest'
 * without performing any copy.
 */

void	*ft_memcpy(void *dest, void const *src, size_t n)
{
	size_t		i;
	char		*new_dest;
	char const	*new_src;

	i = 0;
	if (n == 0 || dest == src)
	{
		return (dest);
	}
	new_dest = (char *) dest;
	new_src = (char const *) src;
	while (i < n)
	{
		new_dest[i] = new_src[i];
		i++;
	}
	return (dest);
}
