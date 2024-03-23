/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 21:39:00 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/23 21:39:00 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libunit.h"

int	check_output(int fd, char **expected, size_t len)
{
	size_t	i;
	char	*fline;
	int		ret;

	i = 0;
	fline = get_next_line(fd);
	ret = 0;
	while (fline && i < len)
	{
		if (ft_strncmp(fline, expected[i], ft_strlen(expected[i])) != 0)
			ret = -1;
		free(fline);
		fline = get_next_line(fd);
	}
	return (ret);
}
