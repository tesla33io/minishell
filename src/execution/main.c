/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:01:11 by astavrop          #+#    #+#             */
/*   Updated: 2024/05/21 20:24:52 by astavrop         ###   ########.fr       */
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
	char	**keys;
	int		len;

	ht_clear(test_ht);
	generate_envp_ht(test_ht, envp);
	len = ht_len(test_ht);
	keys = ht_get_keys(test_ht);
	for (int i = 0; i < len; i++)
	{
		printf("%s=", keys[i]);
		printf("%s\n", ht_get(test_ht, keys[i]));
	}
}
