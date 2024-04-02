/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 21:36:55 by astavrop          #+#    #+#             */
/*   Updated: 2024/04/02 14:00:30 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include "../../libunit/framework/includes/libunit.h"

#include "../../../include/builtins.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	test_echo_basic(void)
{
	int	check_fd;
	int	res;
	char	*tfname;

	tfname = "test_echo_basic.test";
	check_fd = open(tfname, O_RDWR | O_CREAT, 777);
	ft_echo(check_fd, 1, (char *[]){"This is simple string"});
	res = check_output(tfname, (char *[]){"This is simple string\n"}, 1);
	close(check_fd);
	unlink(tfname);
	return (res);
}

int	test_echo_no_nl(void)
{
	int	check_fd;
	int	res;
	char	*tfname = "test_echo_no_nl.test";

	check_fd = open(tfname, O_RDWR | O_CREAT, 777);
	ft_echo(check_fd, 2, (char *[]){"-n", "This is simple string"});
	res = check_output(tfname, (char *[]){"This is simple string"}, 1);
	close(check_fd);
	unlink(tfname);
	return (res);
}

int	test_echo_two_args(void)
{
	int	check_fd;
	char	*test_name = "test_echo_two_args.test";
	int	res;

	check_fd = open(test_name, O_RDWR | O_CREAT, 777);
	dup2(check_fd, STDOUT_FILENO);
	ft_echo(check_fd, 2, (char *[]){"arg1", "arg2"});
	res = check_output(test_name, (char *[]){"arg1 arg2\n"}, 1);
	close(check_fd);
	unlink(test_name);
	return (res);
}

int	test_echo_many_args(void)
{
	int	check_fd;
	char	*test_name = "test_echo_many_args.test";
	int	res;

	check_fd = open(test_name, O_RDWR | O_CREAT, 777);
	ft_echo(check_fd, 5, (char *[]){"arg1", "arg2", "arg3", "arg4   ", "   arg5", NULL});
	res = check_output(test_name, (char *[]){"arg1 arg2 arg3 arg4       arg5\n"}, 1);
	close(check_fd);
	unlink(test_name);
	return (res);
}
