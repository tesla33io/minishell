/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 21:52:38 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/12 15:51:23 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Signals handling in the shell */

#include <stdio.h>
#include <readline/readline.h>
#include <unistd.h>

void	sh_sigint_handler(int signum)
{
	(void)signum;
	write(STDOUT_FILENO, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}
