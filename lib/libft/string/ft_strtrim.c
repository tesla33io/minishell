/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:01:16 by astavrop          #+#    #+#             */
/*   Updated: 2023/11/17 19:42:04 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	in_set(char const c, char const *set)
{
	while (*set)
	{
		if (c == (char) *set)
			return (1);
		set++;
	}
	return (0);
}

/**
 * Calculates the starting index of the substring in 's' that does not contain
 * characters from 'set'.
 *
 * @param s    The input string.
 * @param set  The reference set of characters to trim.
 * @return     The starting index of the substring without 'set' characters.
 *
 * This function calculates the starting index of the non-'set' characters in
 * the input string 's'.
 */

static size_t	calc_start(char const *s, char const *set)
{
	size_t	start;

	start = 0;
	while (s[start] && in_set(s[start], set))
		start++;
	return (start);
}

/**
 * Calculates the length of the substring in 's' without 'set' characters,
 * starting from 'start'.
 *
 * @param s      The input string.
 * @param set    The reference set of characters to trim.
 * @param start  The starting index of the substring without 'set' characters.
 * @return       The length of the substring without 'set' characters.
 *
 * This function calculates the length of the substring without 'set'
 * characters, starting from 'start'.
 *
 * why 's[end - 1]'? end initially points to the position where the
 * null-terminator '\0'
 */

static size_t	calc_len(char const *s, char const *set, size_t start)
{
	size_t	end;

	end = (size_t) ft_strlen((char *) s);
	while (end > start && in_set(s[end - 1], set))
		end--;
	return (end - start);
}

/**
 * Allocates memory and returns a copy of 's1' with characters specified
 * in 'set' removed from the beginning and the end of the string.
 *
 * @param s1   The string to be trimmed.
 * @param set  The reference set of characters to trim.
 * @return     The trimmed string.
 *             NULL if the allocation fails.
 */

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	len;
	size_t	i;
	char	*result;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = calc_start(s1, set);
	len = calc_len(s1, set, start);
	result = (char *) malloc((len * sizeof(char)) + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = s1[start + i];
		i++;
	}
	result[len] = '\0';
	return (result);
}
