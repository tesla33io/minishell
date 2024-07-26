/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:20:48 by astavrop          #+#    #+#             */
/*   Updated: 2024/07/26 22:13:19 by astavrop         ###   ########.fr       */
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
	 	rlret = ft_strdup("");
	shd->lexer->cmd_line = rlret;
	if (ft_strncmp(rlret, "", 1) != 0)
		add_history(rlret);
	if (!shd->lexer->cmd_line)
		return (0);
	return (1);
}
