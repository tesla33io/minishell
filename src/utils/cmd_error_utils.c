/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_error_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:27:21 by astavrop          #+#    #+#             */
/*   Updated: 2024/05/20 19:54:30 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
