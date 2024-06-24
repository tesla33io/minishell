/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 21:24:24 by astavrop          #+#    #+#             */
/*   Updated: 2024/06/24 21:39:12 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"

#include <linux/limits.h>
#include <stdio.h>
#include <unistd.h>

int	cd_builtin(t_Command *cd)
{
	char	*old_pwd;

	if (!cd->args[1])
		return (-1);
	old_pwd = getcwd(NULL, PATH_MAX);
	if (!old_pwd)
		perror("cd");
	if (chdir(cd->args[1]) != 0)
		perror("cd");
	// TODO: set env PWD and OLDPWD
	return (0);
}
