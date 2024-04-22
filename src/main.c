/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 23:05:57 by astavrop          #+#    #+#             */
/*   Updated: 2024/04/22 18:13:58 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(void)
{
/*
	(void)ac;
	(void)av;
	t_CommandNode	*pipen;
	t_SimpleCommand	*l;
	t_CommandNode	*lnode;
	t_SimpleCommand	*r;
	t_CommandNode	*rnode;
	int				status = 0;

	pipen = malloc(sizeof(t_CommandNode));
	lnode = malloc(sizeof(t_CommandNode));
	rnode = malloc(sizeof(t_CommandNode));
	if (!pipen)
		return (-1);
	l = cmd_gen("ls", (char *[]){"ls", "/home/astavrop", NULL}, envp,
			-1, -1, (int [2]){-1, -1});
	r = cmd_gen("echo", (char *[]){"echo", NULL}, envp,
			-1, -1, (int [2]){-1, -1});

	print_command(r);
	print_command(l);
	status = 0;
	cmd_exe(l, 0);
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
	ft_export("TESLA", "33IO", &envp);
	ft_export("TESLA", "USER", &envp);
	ft_export("USER", "minishell", &envp);
	ft_export("USER_2", "me", &envp);
	ft_unset("LOGNAME", &envp);
	ft_env(envp);
	// free_envp(envp);
	return (status);
  */
	t_shell_data *shell_data;

	shell_data = malloc(sizeof(t_shell_data));
	while (1)
	{
		init(shell_data);
		render_prompt(shell_data);
		lexer(shell_data->lexer);
		//takeout_trash(shell_data);
	}
	return (0);
}
