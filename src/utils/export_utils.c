/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_uitls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 22:19:15 by astavrop          #+#    #+#             */
/*   Updated: 2024/04/30 22:24:41 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft/libft.h"

char	**ft_split_name_value(char const *s)
{
	char	**name_value;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	name_value = ft_malloc(NULL, sizeof(char *) * 3);
	i = 0;
	j = 0;
	while (s[i] != '\0' && s[i] != '=')
		i++;
	name_value[0] = ft_substr(s, 0, i);
	while (s[i + j] != '\0')
		j++;
	name_value[1] = ft_substr(s, i, j);
	name_value[2] = NULL;
	return (name_value);
}
