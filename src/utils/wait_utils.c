/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 13:18:03 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/30 13:18:45 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/executor.h"

#include <sys/wait.h>

int	w_check(int status)
{
	if (WIFSIGNALED(status))
		return (WTERMSIG(status));
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (-1);
}
