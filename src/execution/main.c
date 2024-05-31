/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:01:11 by astavrop          #+#    #+#             */
/*   Updated: 2024/05/31 20:33:31 by astavrop         ###   ########.fr       */
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

	char	*v1[] = {"ls", "-lR", NULL};
	char	*v2[] = {"grep", "r-", NULL};
	char	*v3[] = {"grep", "16", NULL};

	t_Command	cmd1 = {v1[0], v1, envp, 0, 1};
	t_Command	cmd2 = {v2[0], v2, envp, 0, 1};
	t_Command	cmd3 = {v3[0], v3, envp, 0, 1};

	t_Command	*cmds[] = {&cmd1, &cmd2, &cmd3};

	t_Pipeline pip = {cmds, 3};

	execute_pipeline(&pip);
}
