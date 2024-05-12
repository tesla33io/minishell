/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 23:05:57 by astavrop          #+#    #+#             */
/*   Updated: 2024/05/18 17:58:18 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/executor.h"
#include "../include/builtins.h"

#include "../lib/libft/libft.h"

#include <stdlib.h>
#include <stdio.h>

/* Test code */
int	main2(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	(void)envp;
	if (ac < 2)
		return (printf("wtf???\n"));
	int				status = 0;
	t_SimpleCommand	*cmd = malloc(sizeof(*cmd));
	if (!cmd)
		return (-1);
	t_kv	envp_ht[TABLE_SIZE];
	clear_hash_table(envp_ht);
	ft_envdup(envp_ht, envp);
	cmd = cmd_gen(av[1], (char *[]) {av[1], av[2]}, envp_ht, 0, 1, (int [2]) {-1, -1});
	switch (hash(av[1])) {
		case 440815: // echo
			ft_echo(cmd);
			break;
		case 1684: // cd
			ft_cd(cmd);
			cmd = cmd_gen("pwd", (char *[]) {"pwd", NULL}, envp_ht, 0, 1, (int [2]) {-1, -1});
		case 30676: // pwd
			ft_pwd(cmd);
			break;
		case 27734: // env
			ft_env(cmd);
			break;
		case 114259604: // export
			ft_export(cmd);
			break;
		case 8149444: // unset
			break;
		default:
			execute_command(cmd);
			break;
	}
	return (status);
}

int	main(int ac, char *av[], char *envp[])
{
	(void)av;
	if (ac < 1)
		return (1);
	t_SimpleCommand *cmd; // = ft_malloc(NULL, sizeof(*cmd));
	t_kv			envp_ht[TABLE_SIZE];
	ft_envdup(envp_ht, envp);
	cmd = cmd_gen("ls", (char *[]) {"ls", NULL}, envp_ht, 0, 1, (int [2]) {-1, -1});
	execute_command(cmd);
	return (0);
}
