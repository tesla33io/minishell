/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 20:13:31 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/02 18:57:14 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"

#include <unistd.h>
#include <wait.h>

char	*ft_path_join(char *path1, char *path2)
{
	char	*new_path;

	if (path1[ft_strlen(path1) - 1] != '/')
	{
		path1 = ft_strjoin(path1, "/");
		if (!path1)
			return (NULL);
	}
	new_path = ft_strjoin(path1, path2);
	return (new_path);
}

unsigned char	set_last_exit_code(int code, int flag)
{
	static unsigned char	last_exit_code;

	if (flag == 'g')
		return (last_exit_code);
	else
		last_exit_code = (unsigned char) code;
	return (last_exit_code);
}

int	get_exit_code(pid_t pid)
{
	int	status;

	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status))
		return (WTERMSIG(status));
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}
