/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_execution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 21:28:23 by astavrop          #+#    #+#             */
/*   Updated: 2024/04/02 20:51:34 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include "../../libunit/framework/includes/libunit.h"

#include "../../../include/executor.h"
#include <stdio.h>
#include <unistd.h>

extern char **environ;

int	test_ls_spec_path(void)
{
	t_SimpleCommand	*ls;
	char			**envp;
	int				out_fd;
	int				res;
	char			*tfname = "test_ls_spec_path.test";

	out_fd = open(tfname, O_WRONLY | O_CREAT, 777);
	dup2(out_fd, 1);
	envp = environ;
	ls = cmd_gen("ls", (char *[]){"ls", "executor/simpleCommand/test_ls_dir/", NULL},
			envp, -1, -1, (int []){-1, -1});
	cmd_exe(ls, 0);
	close(out_fd);
	res = check_output(tfname,
			(char *[]){"file1.txt\n", "file2.txt\n", "file3.txt\n", NULL}, 3);
	unlink(tfname);
	return (res);
}
