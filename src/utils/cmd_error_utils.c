/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_error_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:29:35 by astavrop          #+#    #+#             */
/*   Updated: 2024/07/26 18:29:36 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft/libft.h"

#include <stdio.h>

int	fork_fail(void)
{
	perror("fork");
	return (-1);
}

int	execve_fail(void)
{
	perror("execve");
	return (-2);
}

int	cmd_not_found(char *name)
{
	ft_putstr_fd(name, 2);
	ft_putendl_fd(": command not found", 2);
	return (127);
}
