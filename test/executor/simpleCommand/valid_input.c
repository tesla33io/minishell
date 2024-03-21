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

#include "../../../include/executor.h"
#include "../../../lib/libft/libft.h"

#include <stdlib.h>

#define AUDIT_IMPLEMENTATION
#include "../../audit.h"
audit("SimpleCommnd test [find_bin]")
{
	t_SimpleCommand	*ls;
	char			*envp;

	envp = getenv("PATH");
	ls = cmd_gen("ls", (char *[]){"ls", NULL}, &envp, 
			(char **){NULL}, (char **){NULL}, (int [2]){-1, -1});
	check(ls != NULL, "lorem", "ipsum");
	check_eq(ft_strncmp(ls->bin, "ls", 2), 0, "%i", "str lorem");
	find_bin(ls);
	check_eq(ft_strncmp(ls->bin, "/bin/ls", 7), 0, "%i", "str2 lorem");
}
