/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:56:12 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/24 17:56:12 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include "../../libunit/framework/includes/libunit.h"

#include "../../../include/builtins.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int	test_cd_basic(void)
{
	char	cwd_before[100];
	char	cwd_after[100];

	getcwd(cwd_before, 100);
	ft_cd(getenv("HOME"));
	getcwd(cwd_after, 100);
	if (ft_strncmp(cwd_before, cwd_after, 100) == 0)
		return (-1);
	if (ft_strncmp(cwd_before, cwd_after, ft_strlen(cwd_after)) != 0)
		return (-1);
	return (0);
}

int	test_cd_invalid_path(void)
{
	char	cwd_before[100];
	char	cwd_after[100];
	int		fd;
	int		res;

	fd = open("test_cd.test", O_RDWR | O_CREAT, 777);
	dup2(fd, 2);
	getcwd(cwd_before, 100);
	ft_cd("/home/astavrop_invalid_path");
	getcwd(cwd_after, 100);
	res = check_output(fd, (char *[]){
			"cd: No such file or directory: /home/astavrop_invalid_path\n",
			NULL}, 1);
	close(fd);
	unlink("test_cd.test");
	if (ft_strncmp(cwd_before, cwd_after, 100) != 0)
		return (-1);
	return (res);
}
