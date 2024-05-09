/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:33:48 by astavrop          #+#    #+#             */
/*   Updated: 2024/05/09 21:50:31 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

#include <stdlib.h>

char	**ft_strarray_alloc(int	str_num)
{
	char	**str_array;

	if (str_num < 0)
		return (NULL);
	str_array = ft_malloc(NULL, sizeof(char *) * (str_num + 1));
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
		ft_free_ptr(array[i]);
		i++;
	}
}
