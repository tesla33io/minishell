/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 21:15:07 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/08 20:00:16 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"
#include "../../lib/libft/libft.h"

#include <stdlib.h>

static int	ft_is_numeric(char *s);
static void	non_numeric(char *arg, int num);

int	exit_builtin(t_Command *e)
{
	int	ecode;


	ecode = 0;
	if (e && e->args && e->args[1])
		ecode = ft_atoi(e->args[1]);
	close_extra_fds();
	ft_putendl_fd("exit", 2);
	if (e && e->args && e->args[1] && !ft_is_numeric(e->args[1]) && !e->args[2])
	{
		ecode = 2;
		non_numeric(e->args[1], 1);
	}
	else if (e && e->args && e->args[1] && e->args[2])
	{
		ecode = 1;
		non_numeric(e->args[1], 2);
	}
	gc_free_gc(0);
	gc_free_gc(5);
	exit(ecode);
}

static void	non_numeric(char *arg, int num)
{
	if (num == 1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd("exit: ", 2);
		ft_putstr_fd(arg, 2);
		ft_putendl_fd(": numeric argument required", 2);
	}
	else
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd("exit: ", 2);
		ft_putendl_fd("too many arguments", 2);
	}
}

static int	ft_is_numeric(char *s)
{
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}
