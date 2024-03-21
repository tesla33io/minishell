/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:50:33 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/21 20:50:33 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Unity/src/unity.h"
#include "../../include/executor.h"
#include "tests.h"

int	main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;

	UNITY_BEGIN();

	RUN_TEST(test_find_bin_test);

	UNITY_END();
	return (0);
}
