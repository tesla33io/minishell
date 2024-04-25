/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 20:53:25 by astavrop          #+#    #+#             */
/*   Updated: 2024/04/25 21:02:59 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include "../../libunit/framework/includes/libunit.h"

#include "../../../include/builtins.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	test_env_basic(void)
{
	int		check_fd;
	int		res;
	char	*tfname;

	tfname = "test_env_basic.test";
	check_fd = open(tfname, O_RDWR | O_CREAT, 777);
	dup2(check_fd, STDOUT_FILENO);
	ft_env((char *[]){"K1=V1", "K2=V2", NULL});
	res = check_output(tfname, (char *[]){
				"K1=V1\n", "K2=V2\n", NULL
			}, 2);
	close(check_fd);
	unlink(tfname);
	return (res);
}
