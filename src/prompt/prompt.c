/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:20:48 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/30 23:27:07 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

#include <unistd.h>
#include <stdio.h> /* TODO: remove; for printf() */
#include <readline/readline.h>
#include <readline/history.h>

int	render_prompt(t_shell_data *shell_data)
{
	char	cwd[256];

	getcwd(cwd, sizeof(cwd));
	if (cwd[0] == 0)
		return (-1);
	printf("$🔱 minihell 🔥 [%s]> ", cwd);
	shell_data->lexer->cmd_line = readline("");
	// if command_line == exit -> clear history, free_all, exit
	printf("%s\n", shell_data->lexer->cmd_line);
	//rl_replace_line(shell_data->lexer->cmd_line, 0);
	//rl_redisplay();
	return (0);
}
