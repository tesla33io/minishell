/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:20:48 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/20 16:43:19 by ltreser          ###   ########.fr       */
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
	printf("%s\n", input);
	return (0);
}
