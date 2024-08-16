/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:20:48 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/16 19:11:45 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../include/builtins.h"

#include <linux/limits.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

static int	only_whitspaces(char *str);

int	render_prompt(t_shell_data *shd)
{
	char	*rlret;

	rlret = readline("PROMPT HERE: ");
	if (!rlret)
		exit_builtin(NULL);
	if (ft_strncmp(rlret, "", 1) == 0 || only_whitspaces(rlret) == 1)
	{
		gc_free_ptr((void **) &rlret);
		return (-1);
	}
	if (ft_strncmp(rlret, "", 1) != 0 && only_whitspaces(rlret) != 1)
		add_history(rlret);
	shd->lexer->cmd_line = ft_strdup(rlret);
	if (rlret)
		gc_free_ptr((void **) &rlret);
	if (!shd->lexer->cmd_line)
		return (-1);
	return (0);
}

static int	only_whitspaces(char *str)
{
	size_t	len;
	size_t	skipped;

	len = 0;
	skipped = 0;
	while (str[len])
	{
		if (str[len] == 9 || str[len] == 32)
			skipped++;
		len++;
	}
	if (len == skipped)
		return (1);
	return (0);
}
