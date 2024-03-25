/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:50:33 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/21 20:50:33 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

#include "../../include/executor.h"
#include <fcntl.h>
#include <stdio.h>

int	simple_cmd_launcher(void)
{
	t_unit_test	*tlst;

	tlst = NULL;
	load_test(&tlst, "SimpleCommand", "find_bin ls", test_find_bin_ls_ok);
	load_test(&tlst, "SimpleCommand", "find_bin args", test_find_bin_args_ok);
	load_test(&tlst, "SimpleCommand", "find_bin invalid cmd",
			test_find_bin_null);
	return (launch_test(&tlst));
}

int	echo_cmd_launcher(void)
{
	t_unit_test	*tlst;

	tlst = NULL;
	load_test(&tlst, "echo", "string w/ \\n", test_echo_basic);
	load_test(&tlst, "echo", "string w/o \\n", test_echo_no_nl);
	load_test(&tlst, "echo", "two args", test_echo_two_args);
	load_test(&tlst, "echo", "many args", test_echo_many_args);
	return (launch_test(&tlst));
}

int	cd_cmd_launcher(void)
{
	t_unit_test	*tlst;

	tlst = NULL;
	load_test(&tlst, "cd", "go to home", test_cd_basic);
	load_test(&tlst, "cd", "invalid path", test_cd_invalid_path);
	return (launch_test(&tlst));
}

int	main(void)
{
	int	res;

	res = 0;
	res += simple_cmd_launcher();
	res += echo_cmd_launcher();
	res += cd_cmd_launcher();
	return (res);
}
