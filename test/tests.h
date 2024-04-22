/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:43:33 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/30 21:21:34 by ltreser          ###   ########.fr       */
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

/* Tests for `get_token` */

int test_dollarsign(void);
int test_ampersand(void);
int test_questionmark(void);
int test_pipe(void);
int test_parenthesis(void);
int test_doublequotes(void);
int test_singlequotes(void);
int test_asterisk(void);
int test_comparison(void);
int test_space(void);
int test_tab(void);
int test_str(void);
int token_launcher1(void);
int token_launcher2(void);
int token_launcher3(void);


#endif
