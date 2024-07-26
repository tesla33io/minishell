/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:42:30 by astavrop          #+#    #+#             */
/*   Updated: 2024/07/26 18:32:49 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"
#include "../../include/colors.h"

#include <stddef.h>
#include <stdio.h> /* DELETE */
#include <string.h>
#include <unistd.h>

static int	check_if_path_to_bin(char *bin_name);

char	*ft_getenv(char **envp, char *name)
{
	char	*var;
	int		i;

	i = 0;
	var = NULL;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], name, ft_strlen(name)) == 0)
		{
			var = envp[i] + 5;
			break ;
		}
		i++;
	}
	return (var);
}

char	*check_exec_binary(char *path, char *bin_name)
{
	char	**path_entries;
	char	*tmp_bin_name;
	int		i;

	if (check_if_path_to_bin(bin_name))
		return (bin_name);
	path_entries = ft_split(path, ':');
	if (!path_entries)
		return (NULL);
	i = 0;
	while (path_entries[i] != NULL)
	{
		tmp_bin_name = ft_path_join(path_entries[i], bin_name);
		if (!tmp_bin_name)
			return (printf("ft_path_join failed.\n"), NULL);
		if (access(tmp_bin_name, F_OK) == 0 && access(tmp_bin_name, X_OK) == 0)
		{
			ft_strarray_free(path_entries);
			return (tmp_bin_name);
		}
		i++;
	}
	cmd_not_found(bin_name);
	return (NULL);
}

static int	check_if_path_to_bin(char *bin_name)
{
	return ((ft_strncmp(bin_name, "../", 3) == 0
			|| ft_strncmp(bin_name, "./", 2) == 0
			|| ft_strncmp(bin_name, "/", 1) == 0)
		&& access(bin_name, X_OK) == 0);
}
