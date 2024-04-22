/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:45:46 by astavrop          #+#    #+#             */
/*   Updated: 2024/04/22 18:13:21 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft/libft.h"
#include "../../include/builtins.h"

static char	**shift_entries(char *envp[], int start);

void	ft_unset(char *name, char **envp[])
{
	int		i;
	char	**tmp_envp;

	i = 0;
	tmp_envp = *envp;
	while (tmp_envp[i])
	{
		if (envp_keycmp(name, tmp_envp[i], ft_strlen(name)) == 0)
		{
			ft_free_ptr(tmp_envp[i]);
			tmp_envp = shift_entries(tmp_envp, i);
		}
		i++;
	}
	*(envp) = tmp_envp;
}

static char	**shift_entries(char *envp[], int start)
{
	while (envp[start + 1])
	{
		envp[start] = envp[start + 1];
		start++;
	}
	envp[start] = NULL;
	return (envp);
}
