/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:33:48 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/14 22:40:27 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

#include <stdlib.h>

static void	*dup_failed(char **new_arr, int duped);

size_t	ft_strarray_len(char **array)
{
	size_t	len;

	len = 0;
	while (array != NULL && array[len] != NULL)
		len++;
	return (len);
}

int	ft_strarray_dup(char **src_array, char **dest_array)
{
	size_t	i;

	i = 0;
	while (src_array != NULL && src_array[i] != NULL)
	{
		dest_array[i] = ft_strdup(src_array[i]);
		if (!dest_array[i])
		{
			while (i > 0)
			{
				i--;
				gc_free_ptr((void **) &dest_array[i]);
			}
			return (-1);
		}
		i++;
	}
	return (i);
}

char	**ft_strarray_append(char **array, char *new_str)
{
	size_t	len;
	int		duped;
	char	**new_array;

	if (array == NULL)
		len = 0;
	else
		len = ft_strarray_len(array);
	new_array = gc_malloc((sizeof(char *)) * (len + 2));
	if (!new_array)
		return (NULL);
	if (array != NULL)
	{
		duped = ft_strarray_dup(array, new_array);
		if (duped < 0 && (gc_free_ptr((void **) &new_array), 1))
			return (NULL);
	}
	else
		duped = 0;
	new_array[duped] = ft_strdup(new_str);
	if (!new_array[duped])
		return (dup_failed(new_array, duped));
	new_array[duped + 1] = NULL;
	return (new_array);
}

static void	*dup_failed(char **new_arr, int duped)
{
	while (duped > 0)
	{
		duped--;
		gc_free_ptr((void **) &new_arr[duped]);
	}
	gc_free_ptr((void **) &new_arr);
	return (NULL);
}
