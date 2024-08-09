/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:28:07 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/09 16:11:30 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static void	restore_stdfd(int stdoutcp, int stdincp);
static t_shell_data	*dup_envp_and_stdfds(char **envp);

int	main(int ac, char *av[], char *envp[])
{
	t_shell_data	*shd;

	(void)ac;
	(void)av;
	signal(SIGINT, sh_sigint_handler);
	sigaction(SIGQUIT, &(struct sigaction){.sa_handler = SIG_IGN}, NULL);
	gc_set_storage(5);
	shd = dup_envp_and_stdfds(envp);
	if (!shd)
		return (1);
	while (1)
	{
		init(shd);
		if (render_prompt(shd) != -1)
		{
			lexer(shd->lexer);
			ft_parse(shd, ft_strdup(COMPLETE_COMMAND),
				shd->ast->root, shd->lexer->head);
			adapt(shd->ast->root, shd);
			restore_stdfd(shd->stdoutcp, shd->stdincp);
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

static t_shell_data	*dup_envp_and_stdfds(char **envp)
{
	t_shell_data	*shell_data;
	
	shell_data = gc_malloc(sizeof(t_shell_data));
	shell_data->envpv = ft_strarray_alloc(ft_strarray_len(envp));
	ft_strarray_dup(envp, shell_data->envpv);
	if (!shell_data->envpv)
		return (NULL);
	shell_data->stdoutcp = dup(STDOUT_FILENO);
	shell_data->stdincp = dup(STDIN_FILENO);
	return (shell_data);
}
