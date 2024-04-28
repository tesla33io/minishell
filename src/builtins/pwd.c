/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:47:25 by astavrop          #+#    #+#             */
/*   Updated: 2024/04/28 19:07:38 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft/libft.h"

#include <errno.h>
#include <linux/limits.h>
#include <string.h>
#include <unistd.h>

void	ft_pwd(t_SimpleCommand *cmd)
{
	char	cp[PATH_MAX];
	char	*ret;
	int		errnum;
	(void)cmd;

	ret = getcwd(cp, PATH_MAX);
	if (ret)
		ft_putendl_fd(cp, STDOUT_FILENO);
	else
	{
		errnum = errno;
		ft_putstr_fd("pwd: ", STDERR_FILENO);
		ft_putstr_fd(strerror(errnum), STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
	}
}
