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

int	test_find_bin_ls(void)
{
	t_SimpleCommand	*ls;
	char			*envp;

	envp = getenv("PATH");
	ls = cmd_gen("ls", (char *[]){"ls", NULL}, &envp, 
			(char **){NULL}, (char **){NULL}, (int [2]){-1, -1});
	ft_printf("Generate `ls` cmd.\n");
	if (ls == NULL)
		return (-1);
	ft_printf("Check result of generation\n");
	if (ft_strncmp("ls", ls->bin, ft_strlen(ls->bin)) == 0)
	{
		ft_printf("Look for `ls` binary.\n");
		find_bin(ls);
		ft_printf("%s\n", ls->bin);
		if (ft_strncmp("/usr/bin/ls", ls->bin, ft_strlen(ls->bin)) == 0)
		{
			free(ls);
			return (0);
		}
	}
	free(ls);
	return (-1);
}
