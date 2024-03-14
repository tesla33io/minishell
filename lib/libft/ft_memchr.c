/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:29:16 by astavrop          #+#    #+#             */
/*   Updated: 2023/11/26 22:26:06 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Searches for the first occurrence of the character 'c' in the first 'n' bytes
 * of the memory block pointed to by 'src'.
 *
 * @param src Pointer to the memory area to be searched.
 * @param c   Character to be located.
 * @param n   Number of bytes to be searched.
 * @return    Pointer to the first occurrence of 'c' within the 'n' bytes of
 *            memory pointed to by 'src', or NULL if 'c' is not found.
 *
 * This function searches for the character 'c' in the memory block pointed to
 * by 'src'. It iterates through the memory block 'n' bytes at most or until 'c'
 * is found. If 'c' is found within the first 'n' bytes, the function returns a
 * pointer to the location where 'c' is found. If 'c' is not found within the
 * specified 'n' bytes, the function returns NULL.
 */

void	*ft_memchr(const void *src, int c, size_t n)
{
	unsigned char	*s;
	unsigned char	chr;

	s = (unsigned char *) src;
	chr = (unsigned char) c;
	while (n > 0)
	{
		if (*s == chr)
			return ((void *) s);
		s++;
		n--;
	}
	return (NULL);
}
