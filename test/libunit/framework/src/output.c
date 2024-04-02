/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 21:39:00 by astavrop          #+#    #+#             */
/*   Updated: 2024/04/02 14:15:06 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libunit.h"

#include <limits.h>
#include <unistd.h>

int	check_output(char *fname, char **expected, size_t len)
{
	size_t	i;
	char	*fline;
	int		ret;
	int		fd;

	i = 0;
	fd = open(fname, O_RDONLY);
	fline = get_next_line(fd);
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
	if (i < len)
		ret = -1;
	close(fd);
	return (ret);
}
