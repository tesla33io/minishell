/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:16:02 by astavrop          #+#    #+#             */
/*   Updated: 2024/04/22 18:34:59 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include "../../libunit/framework/includes/libunit.h"

#include "../../../include/builtins.h"
#include <stdlib.h>

int	test_export_basic_new(void)
{
	char	**envp = malloc(sizeof(char *) * 3);
	envp[0] = "KEY_1=VAL_1";
	envp[1] = "KEY_2=VAL_2";
	envp[2] = NULL;

	ft_export("KEY_3", "VAL_3", &envp);
	if (envp[2])
	{
		if (ft_strncmp(envp[2], "KEY_3=VAL_3", 11) == 0)
			return (0);
	}
	return (-1);
}

int	test_export_add_dupl(void)
{
	char	**envp = malloc(sizeof(char *) * 3);
	envp[0] = "KEY_1=VAL_1";
	envp[1] = "KEY_2=VAL_2";
	envp[2] = NULL;

	ft_export("KEY_2", "VAL_3", &envp);
	if (envp[1])
	{
		if (ft_strncmp(envp[1], "KEY_2=VAL_3", 11) == 0)
			return (0);
	}
	return (-1);
}
