/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:33:48 by astavrop          #+#    #+#             */
/*   Updated: 2024/07/02 17:26:05 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

#include <stdlib.h>

char	**ft_strarray_alloc(int	str_num)
{
	char	**str_array;

	if (str_num < 0)
		return (NULL);
	str_array = gc_malloc(NULL, sizeof(char *) * (str_num + 1));
	if (!str_array)
		return (NULL);
	str_array[str_num] = NULL;
	return (str_array);
}

void	ft_strarray_free(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		gc_free_ptr(array[i]);
		i++;
	}
}

size_t	ft_strarray_len(char **array)
{
	size_t	len;

	len = 0;
	while (array[len] != NULL)
		len++;
	return (len);
}

int	ft_strarray_dup(char **src_array, char **dest_array)
{
	size_t	i;

	i = 0;
	while (src_array[i] != NULL)
	{
		dest_array[i] = ft_strdup(src_array[i]);
		if (!dest_array[i])
			return (-1);
		i++;
	}
	return (i);
}

char	**ft_strarray_append(char **array, char *new_str)
{
	size_t	len;
	int		duped;
	char	**new_array;

	len = ft_strarray_len(array);
	new_array = gc_malloc(NULL, (sizeof(char *)) * (len + 2));
	if (!new_array)
		return (NULL);
	duped = ft_strarray_dup(array, new_array);
	if (duped < 0)
		return (NULL);
	new_array[duped] = ft_strdup(new_str);
	new_array[duped + 1] = NULL;
	return (new_array);
}
