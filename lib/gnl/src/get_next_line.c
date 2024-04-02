/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 22:24:05 by ltreser           #+#    #+#             */
/*   Updated: 2023/10/29 01:59:57 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	static int	start = 0;
	static int	end = 0;
	static int	len = 0;
	static char	*longstr = 0;

	if (fd < 0 || (len && (!longstr)))
		return (len = 0, start = 0, end = 0, free(longstr), longstr = NULL);
	if (longstr && longstr[end] == '\n' && ((end < len && ++end) || end))
		start = end;
	else
	{
		longstr = ft_realloc(&longstr, (BUFFER_SIZE + len + 3), 0);
		len += read(fd, (longstr + len), BUFFER_SIZE);
		if (len < end)
			return (len = 0, start = 0, end = 0, free(longstr), longstr = NULL);
		longstr[len] = '\0';
		if (len == end)
			return (len = 0, str_cutter(&start, &end, &longstr, 1));
	}
	while (end < len && longstr[end] != '\n')
		end++;
	if (end < len && ((longstr[end] == '\n') || (len < BUFFER_SIZE)))
		return (str_cutter(&start, &end, &longstr, 0));
	return (get_next_line(fd));
}
