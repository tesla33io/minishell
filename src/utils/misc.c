/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 20:13:31 by astavrop          #+#    #+#             */
/*   Updated: 2024/07/26 18:33:43 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"

#include <stdio.h>

char	*ft_path_join(char *path1, char *path2)
{
	char	*new_path;

	if (path1[ft_strlen(path1) - 1] != '/')
	{
		path1 = ft_strjoin(path1, "/");
		if (!path1)
			return (NULL);
	}
	new_path = ft_strjoin(path1, path2);
	return (new_path);
}
