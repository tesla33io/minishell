/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 21:10:49 by astavrop          #+#    #+#             */
/*   Updated: 2024/06/09 21:21:12 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"

#include <linux/limits.h>
#include <unistd.h>

int	pwd_builtin(t_Command *pwd)
{
	(void)pwd;
	char	*pwd_value;

	pwd_value = getcwd(NULL, 0);
	ft_putendl_fd(pwd_value, 1);
	return (0);
}
