/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:53:05 by astavrop          #+#    #+#             */
/*   Updated: 2023/11/28 16:18:09 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
s: The string from which to create the substring.
start: The start index of the substring in the
string ’s’.
len: The maximum length of the substring
*/

static char	*alloc(char const *s, unsigned int start, size_t len)
{
	char	*new_s;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len <= start)
	{
		new_s = (char *)malloc(sizeof(char));
		if (!new_s)
			return (NULL);
		new_s[0] = '\0';
	}
	else
	{
		if ((s_len <= len) || (s_len < start + len))
			len = s_len - start;
		new_s = (char *)malloc((len + 1) * sizeof(char));
	}
	return (new_s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_s;
	size_t	i;
	size_t	s_len;

	new_s = alloc(s, start, len);
	if (new_s != NULL)
	{
		s_len = ft_strlen(s);
		i = 0;
		while ((start <= s_len) \
			&& (i < len) \
			&& (s[start] != '\0'))
		{
			new_s[i] = s[start];
			i++;
			start++;
		}
		new_s[i] = '\0';
		return (new_s);
	}
	return (NULL);
}
