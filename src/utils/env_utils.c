/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:57:24 by astavrop          #+#    #+#             */
/*   Updated: 2024/04/20 14:55:08 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft/libft.h"
#include <stdbool.h>

void	free_envp(char *envp[])
{
	int	i;

	i = 0;
	while (envp[i])
	{
		ft_free_ptr(envp[i]);
		i++;
	}
}

char	*create_kv_entry(char *name, char *value)
{
	char	*kv;
	int		total_len;
	int		name_len;
	int		i;

	total_len = ft_strlen(name) + 1 + ft_strlen(value);
	name_len = ft_strlen(name) + 1;
	kv = ft_malloc(NULL, sizeof(char) * total_len);
	i = 0;
	while (i < ft_strlen(name))
	{
		kv[i] = name[i];
		i++;
	}
	kv[i++] = '=';
	while (i - name_len < ft_strlen(value))
	{
		kv[i] = value[i - name_len];
		i++;
	}
	kv[i] = 0;
	return (kv);
}


bool	envp_contains(char *name, char *envp[])
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(name, envp[i], ft_strlen(name) + 1) == 0)
			return (true);
		i++;
	}
	return (false);
}
