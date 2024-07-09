/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 22:24:46 by ltreser           #+#    #+#             */
/*   Updated: 2023/10/29 01:57:59 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char	*str_cutter(int *start, int *end, char **longstr, int free_me)
{
	int		i;
	char	*str;

	i = 0;
	if (*start == *end && (*longstr)[*end] != '\n')
		return (*start = 0, *end = 0, free(*longstr), *longstr = NULL, NULL);
	str = malloc((*end - *start) + 2);
	if (!str)
		return (*start = 0, *end = 0, NULL);
	while (*start <= *end)
		str[i++] = (*longstr)[(*start)++];
	str[i] = '\0';
	if (free_me)
	{
		free(*longstr);
		*longstr = NULL;
		*end = 0;
		*start = 0;
	}
	return (str);
}

char	*ft_realloc(char **ptr, int size, int i)
{
	char	*new_ptr;

	new_ptr = NULL;
	if (*ptr == NULL)
		return (free(new_ptr), malloc(size));
	new_ptr = malloc(size);
	while (new_ptr && i < size - 1 && (*ptr)[i] != '\0')
	{
		new_ptr[i] = (*ptr)[i];
		i++;
	}
	if (new_ptr && i < size)
		new_ptr[i] = '\0';
	free(*ptr);
	*ptr = NULL;
	return (new_ptr);
}
