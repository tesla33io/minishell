/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tokens1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 20:34:31 by ltreser           #+#    #+#             */
/*   Updated: 2024/03/30 21:09:22 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../test.h"
#include "../../libunit/framework/includes/libunit.h"
#include "../../../include/minishell.h"

int	test_dollarsign(void)
{
	if (get_token('$') == '$')
		return (0);
	else
		return (-1);
}

int test_ampersand(void)
{
    if (get_token('&') == '&')
        return (0);
    else
        return (-1);
}

int test_questionmark(void)
{
    if (get_token('?') == '?')
        return (0);
    else
        return (-1);
}

int test_pipe(void)
{
    if (get_token('|') == '|')
        return (0);
    else
        return (-1);
}

int test_parenthesis(void)
{
    if ((get_token(')') == ')') && (get_token('(') == ')'))
        return (0);
    else
        return (-1);
}
