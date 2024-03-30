/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_execution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 21:28:23 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/30 23:46:38 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include "../../libunit/framework/includes/libunit.h"

#include "../../../include/executor.h"
#include <stdio.h>
#include <unistd.h>

int	test_ls_spec_path(void)
{
	t_SimpleCommand	*ls;
	char			*envp;
	int				out_fd;
	int				res;
	char			*tfname = "test_ls_spec_path.test";

	out_fd = open(tfname, O_RDWR | O_CREAT, 776);
	dup2(out_fd, 1);
	dup2(out_fd, 2);
	envp = getenv("PATH");
	ls = cmd_gen("ls", (char *[]){"ls", "executor/simpleCommand/test_ls_dir/", NULL}, &envp,
			-1, -1, (int []){-1, -1});
	cmd_exe(ls, 0);
	res = check_output(out_fd, (char *[]){"file1.txt  file2.txt  file3.txt\n"}, 1);
	unlink(tfname);
	return (res);
}
