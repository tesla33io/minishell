/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 23:05:57 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/19 23:05:59 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/executor.h"
#include "../lib/libft/libft.h"

#include <stdlib.h>
#include <stdio.h>

/* Test code */
int	main(int ac, char **av, char **envp)
{
	t_SimpleCommand	*cmd;

	if (ac == 3)
	{
		cmd = cmd_gen(av[1], (char *[]){av[1], av[2], NULL},
				envp, (char **){NULL}, (char **){NULL}, (int [2]) {-1, -1});
		cmd_exe(cmd);
	}
	else
	{
		printf("WTF\n");
		exit (1);
	}
//	find_bin(&cmd);
//	print_command(&cmd);
	return (0);
}
