/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 21:10:49 by astavrop          #+#    #+#             */
/*   Updated: 2024/07/28 18:51:13 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"

#include <linux/limits.h>
#include <unistd.h>

int	pwd_builtin(t_Command *pwd)
{
	char	*pwd_value;

	(void)pwd;
	pwd_value = getcwd(NULL, 0);
	ft_putendl_fd(pwd_value, 1);
	return (0);
}
