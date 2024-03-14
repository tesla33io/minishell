/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:31:21 by astavrop          #+#    #+#             */
/*   Updated: 2023/11/17 17:50:39 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_s;
	int		i;
	int		j;

	new_s = (char *)malloc(((ft_strlen((char *) s1) + ft_strlen((char *) s2)) \
		* sizeof(char)) + 1);
	if (new_s != NULL)
	{
		i = 0;
		j = 0;
		while (s1[i] != '\0')
		{
			new_s[j++] = s1[i++];
		}
		i = 0;
		while (s2[i] != '\0')
		{
			new_s[j++] = s2[i++];
		}
		new_s[j] = '\0';
		return (new_s);
	}
	return (NULL);
}
