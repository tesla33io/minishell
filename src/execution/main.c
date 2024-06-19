/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:01:11 by astavrop          #+#    #+#             */
/*   Updated: 2024/06/09 21:19:56 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"
#include "../../include/builtins.h"
#include "../../lib/libft/libft.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

#include <string.h> /* TODO: delete */

int	main(int ac, char *av[], char *envp[])
{
	(void)ac;
	(void)av;
	(void)envp;

	int		exit_status = 0;

	pwd_builtin(NULL);

	/* ECHO
	if (ac < 2)
		return (printf("Usage: %s <arguments to echo ...>\n", av[0]));

	char	**args = malloc(sizeof(*args) * (ac));
	if (!args)
		return (dprintf(2, "malloc failed at %s:%d\n", __FILE__, __LINE__));
	for (int i = 0; i < ac; i++)
		args[i] = strdup(av[i]);
	args[ac] = NULL;
	t_Command	echo = {"echo", args, envp, 0, 1};
	exit_status = echo_builtin(&echo);
	*/

	/* CMD + PIPE
	int	openfd = open(av[1], O_RDONLY);
	if (openfd < 0)
		return (printf("open call [%s:%d] error\n", __FILE__, __LINE__));
	*/
	/*
	int openfd = start_heredoc(av[1]);
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

	close(openfd);
	close(dev_nullfd);
	*/

	return (exit_status);
}
