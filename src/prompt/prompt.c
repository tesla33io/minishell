/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:20:48 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/20 17:36:53 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

#include <unistd.h>
#include <stdio.h> /* TODO: remove; for printf() */
#include <readline/readline.h>
#include <readline/history.h>

int	render_prompt(void)
{
	char	cwd[256];
	char	*input;

	getcwd(cwd, sizeof(cwd));
	if (cwd[0] == 0)
		return (-1);
	ft_printf("$🔥🔥minihell🔥🔥 [%s]> ", cwd);
	input = readline("");
	// if input == exit -> clear history, free_all, exit
	printf("%s\n", input);
	rl_replace_line(input, 0);
	rl_redisplay();
	return (0);
}
