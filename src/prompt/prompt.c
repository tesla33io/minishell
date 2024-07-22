/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:20:48 by astavrop          #+#    #+#             */
/*   Updated: 2024/07/22 19:28:44 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

#include <linux/limits.h>
#include <unistd.h>
#include <stdio.h> /* TODO: remove; for printf() */
#include <readline/readline.h>
#include <readline/history.h>

/* TODO: Handle Ctrl+d => exit */
int	render_prompt(t_shell_data *shd)
{
	char	cwd[PATH_MAX];
	char	*rlret;

	getcwd(cwd, sizeof(cwd));
	if (cwd[0] == 0)
		return (-1);
	printf("%s", cwd);
	rlret = readline(" \033[32;1m$$\033[0m ");
	if (rlret && *rlret == 0)
		return (render_prompt(shd));
	shd->lexer->cmd_line = rlret;
	// printf(">> cmd_line: {%s}\n", shd->lexer->cmd_line);
	if (!shd->lexer->cmd_line)
		return (0);
	return (1);
}
