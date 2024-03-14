/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:02:15 by astavrop          #+#    #+#             */
/*   Updated: 2023/11/13 18:49:52 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Locates the first occurrence of a substring 'little' in a string 'big' within
 * 'len' characters.
 *
 * @param big    Pointer to the string to be searched.
 * @param little Pointer to the substring to search for within 'big'.
 * @param len    Maximum number of characters to search within 'big'.
 * @return       Pointer to the located substring within 'big', or NULL if not
 *               found.
 *
 * This function attempts to find the first occurrence of the substring 'little'
 * within the string 'big' limited to 'len' characters. If 'little' points to
 * an empty string, 'big' is returned. If 'little' is not found within the first
 * 'len' characters of 'big', NULL is returned.
 */

char	*ft_strnstr(char *big, char *little, size_t len)
{
	char	*b_clone;
	char	*start;
	size_t	l_size;

	if (*little == '\0')
		return (big);
	b_clone = big;
	l_size = (size_t) ft_strlen(little);
	while (*b_clone != '\0' && len >= l_size)
	{
		start = b_clone;
		if (!ft_strncmp(b_clone, little, l_size))
			return (start);
		b_clone++;
		len--;
	}
	return (NULL);
}
