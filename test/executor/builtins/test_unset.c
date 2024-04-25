/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:24:18 by astavrop          #+#    #+#             */
/*   Updated: 2024/04/25 21:26:05 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include "../../libunit/framework/includes/libunit.h"

#include "../../../include/builtins.h"
#include <stdlib.h>

int	test_unset_basic(void)
{
	char	**envp = malloc(sizeof(char *) * 3);
	envp[0] = "KEY_1=VAL_1";
	envp[1] = "KEY_2=VAL_2";
	envp[2] = NULL;

	ft_unset("KEY_2", &envp);
	if (!envp[1])
		return (0);
	return (-1);
}
