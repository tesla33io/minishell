/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:50:33 by astavrop          #+#    #+#             */
/*   Updated: 2024/04/25 21:28:14 by astavrop         ###   ########.fr       */
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
	load_test(&tlst, "find_bin", "ls", test_find_bin_ls_ok);
	load_test(&tlst, "find_bin", "args", test_find_bin_args_ok);
	load_test(&tlst, "find_bin", "invalid cmd",
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

int	cmd_exe_launcher(void)
{
	t_unit_test	*tlst;

	tlst = NULL;
	load_test(&tlst, "Command execution", "ls test_ls_dir/", test_ls_spec_path);
	return (launch_test(&tlst));
}

int	builtins_launcher(void)
{
	t_unit_test	*tlst;

	tlst = NULL;
	load_test(&tlst, "export", "add new var", test_export_basic_new);
	load_test(&tlst, "export", "change var value", test_export_add_dupl);
	load_test(&tlst, "env", "basic, nothing fancy", test_env_basic);
	load_test(&tlst, "unset", "basic", test_unset_basic);
	return (launch_test(&tlst));
}

int	main(void)
{
	int	res;

	res = 0;
	res += simple_cmd_launcher();
	res += echo_cmd_launcher();
	res += cd_cmd_launcher();
	res += cmd_exe_launcher();
	res += builtins_launcher();
	return (res);
}
