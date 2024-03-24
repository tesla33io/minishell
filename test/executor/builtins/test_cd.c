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

int	test_cd_basic(void)
{
	int	fd;
	int	res;

	fd = open("test_cd_basic.test", O_RDWR | O_CREAT, 777);
	dup2(fd, 1);
	ft_cd("/home/astavrop");
	res = check_output(fd, (char *[]){
			"Dir: /home/astavrop/projects/github/minishell/test\n",
			"Dir: /home/astavrop\n", NULL}, 2);
	dup2(1, fd);
	unlink("/home/astavrop/projects/github/minishell/test/test_cd_basic.test");
	return (res);
}
