/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:01:11 by astavrop          #+#    #+#             */
/*   Updated: 2024/06/02 16:49:18 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

int	main(int ac, char *av[], char *envp[])
{
	(void)ac;
	(void)av;
	(void)envp;

	if (ac < 2)
		return (printf("Usage: %s <name of the input file>\n", av[0]));

	int	openfd = open(av[1], O_RDONLY);
	if (openfd < 0)
		return (printf("open call [%s:%d] error\n", __FILE__, __LINE__));
	int	dev_nullfd = open("/dev/null", O_RDONLY);
	if (dev_nullfd < 0)
		return (printf("open call [%s:%d] error\n", __FILE__, __LINE__));

	char	*v1[] = {"grep", "1", NULL};
	char	*v2[] = {"grep", "2", NULL};
	char	*v3[] = {"grep", "3", NULL};

	t_Command	cmd1 = {v1[0], v1, envp, openfd, 1};
	t_Command	cmd2 = {v2[0], v2, envp, 0, 1};
	t_Command	cmd3 = {v3[0], v3, envp, 0, 1};

	t_Command	*cmds[] = {&cmd1, &cmd2, &cmd3};

	t_Pipeline pip = {cmds, 3};

	execute_pipeline(&pip);
}
