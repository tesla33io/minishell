/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:59:32 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/29 18:36:00 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtins.h"

#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

void	ft_cd(const char *path)
{
	int	errnum;

	if (chdir(path) != 0)
	{
		errnum = errno;
		perror("cd: ");
		perror(strerror(errnum));
		perror(": ");
		perror((char *)path);
		perror("\n");
	}
}
