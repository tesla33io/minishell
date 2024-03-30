/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 23:05:57 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/30 14:45:52 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/executor.h"
#include "../include/builtins.h"

#include "../lib/libft/libft.h"

#include <stdlib.h>
#include <stdio.h>

/* Test code */
int	main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	t_CommandNode	*pipen;
	t_SimpleCommand	*l;
	t_CommandNode	*lnode;
	t_SimpleCommand	*r;
	t_CommandNode	*rnode;
	int				status;

	pipen = malloc(sizeof(t_CommandNode));
	lnode = malloc(sizeof(t_CommandNode));
	rnode = malloc(sizeof(t_CommandNode));
	if (!pipen)
		return (-1);
	l = cmd_gen("ls", (char *[]){"ls", NULL}, envp,
			NULL, NULL, (int [2]){-1, -1});
	r = cmd_gen("grep", (char *[]){"grep", "d", NULL}, envp,
			NULL, NULL, (int [2]){-1, -1});

	printf("COMMANDS:\n");
	print_command(l);
	print_command(r);

	lnode->type = CMD;
	lnode->cmd = l;
	rnode->type = CMD;
	rnode->cmd = r;

	pipen->type = PIPE;
	pipen->cmd = NULL;
	pipen->left = lnode;
	pipen->right = rnode;
	status = process_pipe(pipen);
	return (status);
}
