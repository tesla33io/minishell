/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:20:48 by astavrop          #+#    #+#             */
/*   Updated: 2024/07/31 23:13:36 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

#include <linux/limits.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

/* TODO: Handle Ctrl+d => exit */
int	render_prompt(t_shell_data *shd)
{
	char	*rlret;

	rlret = readline("\033[32;1m€\033[0m ");
	if (!rlret)
	{
		printf("0: %p\n", (*gc_get_storage(0))->next);
		gc_free_gc(0);
		printf("0: %p\n", (*gc_get_storage(0))->next);
		printf("5: %p\n", (*gc_get_storage(5))->next);
		gc_free_gc(5);
		printf("5: %p\n", (*gc_get_storage(5))->next);
		exit (1);
	}
	if (ft_strncmp(rlret, "", 1) == 0)
		return (-1);
	shd->lexer->cmd_line = rlret;
	if (ft_strncmp(rlret, "", 1) != 0)
		add_history(rlret);
	if (!shd->lexer->cmd_line)
		return (-1);
	return (0);
}
