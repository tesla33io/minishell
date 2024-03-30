/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 21:39:00 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/30 23:55:46 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libunit.h"

#include <limits.h>
#include <stdio.h> /* WARN: DELETE */

int	check_output(int fd, char **expected, size_t len)
{
	size_t	i;
	char	*fline;
	int		ret;

	i = 0;
	fline = get_next_line(fd);
	dprintf(2, "[%d]line: %s\n", fd, fline);
	ret = 0;
	while (fline && i < len)
	{
		if (ft_strncmp(fline, expected[i], UINT_MAX) != 0)
			ret = -1;
		free(fline);
		fline = get_next_line(fd);
		i++;
	}
	while (fline)
	{
		free(fline);
		fline = get_next_line(fd);
	}
	if (i != len)
		ret = -1;
	return (ret);
}
