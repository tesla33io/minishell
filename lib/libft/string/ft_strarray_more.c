/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarray_more.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 21:15:45 by astavrop          #+#    #+#             */
/*   Updated: 2024/07/25 22:14:22 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

#include <stdlib.h>

char	**ft_strarray_remove_by_value(char **array, char *str)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	**new_array;

	len = ft_strarray_len(array);
	new_array = malloc((sizeof(char *)) * (len + 1));
	if (!new_array)
		return (NULL);
	i = 0;
	j = 0;
	while (array[i])
	{
		if (ft_strcmp(array[i], str) != 0)
		{
			new_array[j] = ft_strdup(array[i]);
			if (!new_array[j])
			{
				ft_strarray_free(new_array);
				return (NULL);
			}
			j++;
		}
		i++;
	}
	new_array[j] = NULL;
	ft_strarray_free(array);
	return (new_array);
}

char	**ft_strarray_remove_by_index(char **array, size_t index)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	**new_array;

	len = ft_strarray_len(array);
	if (index >= len)
		return (array);

	new_array = malloc((sizeof(char *)) * (len + 1));
	if (!new_array)
		return (NULL);

	i = 0;
	j = 0;
	while (array[i])
	{
		if (i != index)
		{
			new_array[j] = ft_strdup(array[i]);
			if (!new_array[j])
			{
				ft_strarray_free(new_array);
				return (NULL);
			}
			j++;
		}
		i++;
	}
	new_array[j] = NULL;
	ft_strarray_free(array);
	return (new_array);
}
