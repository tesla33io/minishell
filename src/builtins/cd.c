/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:59:32 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/24 16:59:32 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtins.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_cd(const char *path)
{
	char	cwd[100];

	printf("Dir: %s\n", getcwd(cwd, 100));
	chdir(path);
	printf("Dir: %s\n", getcwd(cwd, 100));
}
