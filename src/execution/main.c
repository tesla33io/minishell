/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:01:11 by astavrop          #+#    #+#             */
/*   Updated: 2024/05/25 18:08:51 by astavrop         ###   ########.fr       */
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
	pid_t		cpid;
	int			status = 0;
	t_Command	cmd;

	if (ac <= 1)
		return (printf("wrong input\n"));
	cmd.bin_name = av[1];
	cmd.args = (char *[]) {av[1], av[2], NULL};
	cmd.envpv = ft_strarray_alloc(ft_strarray_len(envp));
	if (!cmd.envpv)
		return (printf("ft_strarray_alloc failed.\n"));
	if (ft_strarray_dup(envp, cmd.envpv) < 0)
		return (printf("ft_strarray_dup failed.\n"));
	cmd.in_fd = 0;
	cmd.out_fd = 1;

	cpid = execute_command_in_child(&cmd);
	waitpid(cpid, &status, 0);
	printf("ret: %d\n", WEXITSTATUS(status));
}
