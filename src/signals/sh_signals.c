/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 21:52:38 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/12 17:24:40 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Signals handling in the shell */

#include "../../include/execution.h"

#include <stdio.h>
#include <readline/readline.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void	sh_sigint_handler(int signum)
{
	(void)signum;
	write(STDOUT_FILENO, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	rl_done = 1;
	set_last_exit_code(130, 's');
}

void	reset_signals(int flag)
{
	if (flag & 1)
		sigaction(SIGQUIT, &(struct sigaction){.sa_handler = SIG_DFL}, NULL);
	if (flag & 2)
		sigaction(SIGINT, &(struct sigaction){.sa_handler = SIG_DFL}, NULL);
}
