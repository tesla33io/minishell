/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:43:33 by astavrop          #+#    #+#             */
/*   Updated: 2024/04/25 21:27:37 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include "../libunit/framework/includes/libunit.h"

/* Tests for `find_bin` */

int		test_find_bin_ls_ok(void);
int		test_find_bin_args_ok(void);
int		test_find_bin_null(void);

/* Tests for `ft_echo` */

int		test_echo_basic(void);
int		test_echo_no_nl(void);
int		test_echo_two_args(void);
int		test_echo_many_args(void);

/* Tests for `ft_cd` */

int		test_cd_basic(void);
int		test_cd_invalid_path(void);

/* Command execution tests */

int		test_ls_spec_path(void);

/* BUILT-IN tests */

int		test_export_basic_new(void);
int		test_export_add_dupl(void);

int		test_env_basic(void);

int		test_unset_basic(void);

#endif
