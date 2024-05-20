/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:01:11 by astavrop          #+#    #+#             */
/*   Updated: 2024/05/20 22:17:40 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"

#include <stdio.h>

int	main(int ac, char *av[], char *envp[])
{
	(void)ac;
	(void)av;
	(void)envp;
	t_kv	test_ht[TABLE_SIZE];
	char	**testv;

	ht_clear(test_ht);
	ht_set(test_ht, "KEY1", (char *) "VALUE1");
	ht_set(test_ht, "KEY2", (char *) "VALUE2");
	ht_set(test_ht, "KEY3", (char *) "VALUE3");
	ht_set(test_ht, "KEY4", (char *) "VALUE4");
	ht_set(test_ht, "KEY5", (char *) "VALUE5");
	ht_set(test_ht, "KEY6", (char *) "VALUE6");
	testv = generate_envpv(test_ht);
	for (int i = 0; i < 6; i++)
	{
		printf("> %s\n", testv[i]);
	}
}
