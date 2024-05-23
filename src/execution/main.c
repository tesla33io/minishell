/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:01:11 by astavrop          #+#    #+#             */
/*   Updated: 2024/05/24 22:36:41 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int	main(int ac, char *av[], char *envp[])
{
	(void)ac;
	(void)av;
	(void)envp;
	t_kv		test_ht[TABLE_SIZE];
	pid_t		cpid;
	int			status = 0;
	t_Command	cmd;

	// test_ht = ht_init();
	ht_clear(test_ht);
	generate_envp_ht(test_ht, envp);
	printf("%p (main)\n", (void *) &test_ht);
	if (ac <= 1)
		return (1);
	cmd.bin_name = av[1];
	cmd.args = (char *[]) {av[1], av[2], NULL};
	ht_copy(test_ht, cmd.envp_ht);
	cmd.envpv = generate_envpv(test_ht);
	cmd.in_fd = 0;
	cmd.out_fd = 1;

	cpid = execute_command_in_child(&cmd);
	waitpid(cpid, &status, 0);
	printf("ret: %d\n", WEXITSTATUS(status));
}
