/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarray_more.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 21:15:45 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/14 22:37:31 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

#include <stdio.h>
#include <stdlib.h>

static int	dup_str(char **dest, char **src, int i, int j);

char	**ft_strarray_alloc(int str_num)
{
	char	**str_array;

	if (str_num < 0)
		return (NULL);
	str_array = gc_malloc((str_num + 1) * sizeof(*str_array));
	if (!str_array)
		return (NULL);
	return (str_array);
}

void	ft_strarray_free(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		gc_free_ptr((void **) &array[i]);
		i++;
	}
	gc_free_ptr((void **) &array);
}

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
		printf("[%ld] %s / %s\n", i, array[i], str);
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
	new_array = gc_malloc(sizeof(char *) * len);
	if (!new_array)
		return (NULL);
	i = -1;
	j = 0;
	while (array[++i])
	{
		if (i != index)
		{
			if (dup_str(new_array, array, i, j++) < 0)
				return (NULL);
		}
	}
	new_array[j] = NULL;
	ft_strarray_free(array);
	*array = *new_array;
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
