/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 23:05:57 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/30 20:39:03 by astavrop         ###   ########.fr       */
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
	l = cmd_gen("ls", (char *[]){"ls", "-lah", NULL}, envp,
			-1, -1, (int [2]){-1, -1});
	r = cmd_gen("greps", (char *[]){"greps", "30", NULL}, envp,
			-1, -1, (int [2]){-1, -1});

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
