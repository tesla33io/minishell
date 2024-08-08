/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 20:13:31 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/07 22:50:34 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <wait.h>
#include <stdio.h>

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

/*int	ft_open(const char *fname, int flags, mode_t mode, int closeall)
{
	static int	fds[MAX_N_FDS] = {-1};
	static int	nfd = 0;

	if (closeall)
	{
		while (nfd >= 0)
			close(fds[nfd--]);
		return (0);
	}
	if (nfd > MAX_N_FDS)
		return (ret_int("reached limit of opened files", "open", 0, -1));
	fds[nfd] = open(fname, flags, mode);
	if (fds[nfd] < 0)
		perror("open");
	return (fds[nfd]++);
}*/

int	close_extra_fds(void)
{
	int	failed;
	int	fd;

	failed = 0;
	fd = 3;
	while (fd < 100)
	{
		if (close(fd) < 0)
			failed++;
		fd++;
	}
	return (failed);
}
