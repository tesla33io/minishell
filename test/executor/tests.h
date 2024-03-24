/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:43:33 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/22 18:43:33 by astavrop         ###   ########.fr       */
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

/* Tests for `ft_cd` */

int		test_cd_basic(void);

#endif
