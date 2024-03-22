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

int	simple_cmd_launcher(void)
{
	t_unit_test	*tlst;

	tlst = NULL;
	load_test(&tlst, "SimpleCommand", "find_bin ls", test_find_bin_ls);
	return (launch_test(&tlst));
}

int	main(void)
{
	return (simple_cmd_launcher());
}
