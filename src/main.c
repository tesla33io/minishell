/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:28:07 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/08 22:07:51 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static void	restore_stdfd(int stdoutcp, int stdincp);

int	main(int ac, char *av[], char *envp[])
{
	t_shell_data	*shell_data;

	(void)ac;
	(void)av;
	signal(SIGINT, sh_sigint_handler);
	sigaction(SIGQUIT, &(struct sigaction){.sa_handler = SIG_IGN}, NULL);
	gc_set_storage(5);
	shell_data = gc_malloc(sizeof(t_shell_data));
	shell_data->envpv = ft_strarray_alloc(ft_strarray_len(envp));
	ft_strarray_dup(envp, shell_data->envpv);
	if (!shell_data->envpv)
		return (1);
	shell_data->stdoutcp = dup(STDOUT_FILENO);
	shell_data->stdincp = dup(STDIN_FILENO);
	while (1)
	{
		init(shell_data);
		if (render_prompt(shell_data) != -1)
		{
			lexer(shell_data->lexer);
			ft_parse(shell_data, ft_strdup(COMPLETE_COMMAND),
				shell_data->ast->root, shell_data->lexer->head);
			adapt(shell_data->ast->root, shell_data);
			restore_stdfd(shell_data->stdoutcp, shell_data->stdincp);
		}
		gc_free_gc(0);
	}
	return (0);
}

static void	restore_stdfd(int stdoutcp, int stdincp)
{
	dup2(stdoutcp, STDOUT_FILENO);
	dup2(stdincp, STDIN_FILENO);
}
