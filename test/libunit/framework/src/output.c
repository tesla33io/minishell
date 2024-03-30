/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 21:39:00 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/30 23:37:49 by astavrop         ###   ########.fr       */
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
	dprintf(2, "---debug---\n");
	fline = get_next_line(fd);
	ret = 2;
	dprintf(2, "fline: %s\n", fline);
	while (fline && i < len)
	{
		dprintf(2, "> `%s`\n> `%s`\n", fline, expected[i]);
		if (ft_strncmp(fline, expected[i], UINT_MAX) != 0)
			ret = -1;
		dprintf(2, "== %d\n", ret);
		free(fline);
		fline = get_next_line(fd);
		i++;
	}
	while (fline)
	{
		free(fline);
		fline = get_next_line(fd);
	}
	return (ret);
}
