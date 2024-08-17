/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 21:10:49 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/17 19:42:41 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"

#include <unistd.h>

int	pwd_builtin(t_command *pwd)
{
	char	*pwd_value;

	(void)pwd;
	pwd_value = getcwd(NULL, 0);
	if (!pwd_value)
		return (builtin_failed(BUILTIN_FAILED, "pwd"));
	ft_putendl_fd(pwd_value, 1);
	return (0);
}
