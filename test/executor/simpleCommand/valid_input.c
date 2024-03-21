/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:18:23 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/21 20:18:23 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Unity/src/unity.h"
#include "../../../include/executor.h"
#include "../tests.h"

#include <stdlib.h>

void	test_find_bin_test(void)
{
	t_SimpleCommand	*ls;
	char			*envp;

	envp = getenv("PATH");
	ls = cmd_gen("ls", (char *[]){"ls", NULL}, &envp, 
			(char **){NULL}, (char **){NULL}, (int [2]){-1, -1});
	TEST_ASSERT(ls != NULL);
	TEST_ASSERT_EQUAL_STRING("ls", ls->bin);
	find_bin(ls);
	TEST_ASSERT_EQUAL_STRING("/bin/ls", ls->bin);
}
