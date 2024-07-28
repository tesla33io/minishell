/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarray_more.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 21:15:45 by astavrop          #+#    #+#             */
/*   Updated: 2024/07/28 18:33:02 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

#include <stdlib.h>

static int	dup_str(char **dest, char **src, int i, int j);

char	**ft_strarray_remove_by_value(char **array, char *str)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	**new_array;

	len = ft_strarray_len(array);
	new_array = gc_malloc((sizeof(char *)) * (len + 1));
	if (!new_array)
		return (NULL);
	i = 0;
	j = 0;
	while (array[i])
	{
		if (ft_strcmp(array[i], str) != 0)
		{
			if (dup_str(new_array, array, i, j) < 0)
				return (NULL);
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
	new_array = gc_malloc((sizeof(char *)) * (len + 1));
	if (!new_array)
		return (NULL);
	i = 0;
	j = 0;
	while (array[i])
	{
		if (i != index)
		{
			if (dup_str(new_array, array, i, j) < 0)
				return (NULL);
			j++;
		}
		i++;
	}
	new_array[j] = NULL;
	ft_strarray_free(array);
	return (new_array);
}

static int	dup_str(char **dest, char **src, int i, int j)
{
	dest[j] = ft_strdup(src[i]);
	if (!dest[j])
	{
		ft_strarray_free(dest);
		return (-1);
	}
	return (0);
}
