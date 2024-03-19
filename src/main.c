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
int	main(int ac, char **av)
{
	t_SimpleCommand	cmd;

	(void)ac;
	(void)av;
	cmd.bin = "executor";
	cmd.args = malloc(3 * sizeof(char *));
	cmd.args[0] = "executor";
	cmd.args[1] = "-a1";
	cmd.args[2] = NULL;
	print_command(&cmd);
	return (0);
}
