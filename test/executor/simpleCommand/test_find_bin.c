/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:18:23 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/21 20:18:23 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

#include "../../../include/executor.h"
#include "../../../lib/libft/libft.h"

#include <stdlib.h>

int	test_find_bin_ls_ok(void)
{
	t_SimpleCommand	*ls;
	char			*envp;

	envp = getenv("PATH");
	ls = cmd_gen("ls", (char *[]){"ls", NULL}, &envp, 
			(char **){NULL}, (char **){NULL}, (int [2]){-1, -1});
	if (ls == NULL)
		return (-1);
	if (ft_strncmp("ls", ls->bin, ft_strlen(ls->bin)) == 0)
	{
		find_bin(ls);
		if (ft_strncmp("/usr/bin/ls", ls->bin, ft_strlen(ls->bin)) == 0)
		{
			free_cmd(ls);
			return (0);
		}
	}
	free_cmd(ls);
	return (-1);
}

int	test_find_bin_args_ok(void)
{
	t_SimpleCommand	*ls;
	char			*envp;

	envp = getenv("PATH");
	ls = cmd_gen("ls", (char *[]){"ls", NULL}, &envp, 
			(char **){NULL}, (char **){NULL}, (int [2]){-1, -1});
	if (ls == NULL)
		return (-1);
	if (ft_strncmp("ls", ls->args[0], ft_strlen(ls->bin)) == 0)
	{
		find_bin(ls);
		if (ft_strncmp("/usr/bin/ls", ls->args[0], ft_strlen(ls->args[0]))
				== 0)
		{
			free_cmd(ls);
			return (0);
		}
	}
	free_cmd(ls);
	return (-1);
}

int	test_find_bin_null(void)
{
	t_SimpleCommand	*cmd;
	char			*envp;

	envp = getenv("PATH");
	cmd = cmd_gen("lorem_ipsum", (char *[]){"lorem_ipsum", NULL}, &envp, 
			(char **){NULL}, (char **){NULL}, (int [2]){-1, -1});
	if (cmd == NULL)
		return (-1);
	find_bin(cmd);
	if (ft_strncmp("lorem_ipsum", cmd->bin, ft_strlen(cmd->bin) != 0))
	{
		free_cmd(cmd);
		return (-1);
	}
	free_cmd(cmd);
	return (0);
}
