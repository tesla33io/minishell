/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 21:24:24 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/12 15:57:09 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"

#include <linux/limits.h>
#include <stdio.h>
#include <unistd.h>

int	cd_builtin(t_Command *cd)
{
	char	*old_pwd;
	int		err;

	if (!cd->args[1])
		return (builtin_failed(BUILTIN_FAILED, "cd"));
	err = 0;
	old_pwd = getcwd(NULL, PATH_MAX);
	if (!old_pwd && ++err)
		perror("cd");
	if (chdir(cd->args[1]) != 0 && ++err)
		perror("cd");
	// TODO: set env PWD and OLDPWD
	return (err);
}
