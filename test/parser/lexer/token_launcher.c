/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_launcher.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 20:59:28 by ltreser           #+#    #+#             */
/*   Updated: 2024/03/30 21:12:58 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "../../libunit/framework/includes/libunit.h"
#include "../../../include/minishell.h"

int	token_launcher1(void)
{
	t_unit_test	*tlst;

	tlst = NULL;
	load_test(&tlst, "token", "$", test_dollarsign);
	load_test(&tlst, "token", "&", test_ampersand);
	load_test(&tlst, "token", "?", test_questionmark);
	load_test(&tlst, "token", "|", test_pipe);
	load_test(&tlst, "token", ") & (", test_parenthesis);
	return (lauch_test(&tlst));
}

int token_launcher1(void)
{
    t_unit_test *tlst;

    tlst = NULL;
    load_test(&tlst, "token", "\"", test_doublequotes);
    load_test(&tlst, "token", "'", test_singlequotes);
    load_test(&tlst, "token", "*", test_asterisk);
    load_test(&tlst, "token", "> & <", test_comparison);
    return (lauch_test(&tlst));
}

int token_launcher1(void)
{
    t_unit_test *tlst;

    tlst = NULL;
    load_test(&tlst, "token", "space", test_space);
    load_test(&tlst, "token", "tab", test_tab);
    load_test(&tlst, "token", "string", test_str);
    return (lauch_test(&tlst));
}

