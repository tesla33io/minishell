/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 23:05:57 by astavrop          #+#    #+#             */
/*   Updated: 2024/04/30 21:55:20 by astavrop         ###   ########.fr       */
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
	int				status = 0;
/*	t_CommandNode	*pipen;
	t_SimpleCommand	*l;
	t_CommandNode	*lnode;
	t_SimpleCommand	*r;
	t_CommandNode	*rnode;

	pipen = malloc(sizeof(t_CommandNode));
	lnode = malloc(sizeof(t_CommandNode));
	rnode = malloc(sizeof(t_CommandNode));
	if (!pipen)
		return (-1);
	l = cmd_gen("ls", (char *[]){"ls", "/home/astavrop", NULL}, envp,
			-1, -1, (int [2]){-1, -1});
	r = cmd_gen("echo", (char *[]){"echo", NULL}, envp,
			-1, -1, (int [2]){-1, -1});
*/
/*	print_command(r);
	print_command(l);

	lnode->type = CMD;
	lnode->cmd = l;
	rnode->type = CMD;
	rnode->cmd = r;

	pipen->type = PIPE;
	pipen->cmd = NULL;
	pipen->left = lnode;
	pipen->right = rnode;
	status = process_pipe(pipen);
	return (status);*/
/*	ft_export("TESLA", "33IO", &envp);
	ft_export("TESLA", "USER", &envp);
	ft_export("USER", "minishell", &envp);
	ft_export("USER_2", "me", &envp);
	ft_unset("LOGNAME", &envp);
	ft_env(envp);
	*/
	// free_envp(envp);
	envp = ft_envdup(envp);
	t_SimpleCommand	*exprt = malloc(sizeof(t_SimpleCommand));
	exprt = cmd_gen("export", (char *[]){"export", NULL},
			envp, 0, 1, (int [2]){-1, -1});
	ft_export(exprt);
	/*envp = exprt->envp;
	t_SimpleCommand	*envc = malloc(sizeof(t_SimpleCommand));
	envc = cmd_gen("env", (char *[]){"env", NULL}, envp, 0, 1,
			(int [2]){-1, -1});
	t_SimpleCommand	*exprt = malloc(sizeof(t_SimpleCommand));
	exprt = cmd_gen("export", (char *[]){"export", "KV1=VAL1", NULL},
			envp, 0, 1, (int [2]){-1, -1});	
	envp = ft_export(exprt);
	ft_env(envc);*/
	return (status);
}
