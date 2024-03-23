/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 21:36:55 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/23 21:36:55 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#include "../../libunit/framework/includes/libunit.h"

#include "../../../include/builtins.h"
#include <fcntl.h>
#include <unistd.h>

int	test_echo_basic(void)
{
	int	check_fd;
	int	res;

	check_fd = open("test_echo_basic.test", O_RDWR | O_CREAT, 777);
	ft_echo(check_fd, 1, (char *[]){"This is simple string"});
	res = check_output(check_fd, (char *[]){"This is simple string\n"}, 1);
	close(check_fd);
	unlink("test_echo_basic.test");
	return (res);
}
