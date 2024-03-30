/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tokens3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 20:44:31 by ltreser           #+#    #+#             */
/*   Updated: 2024/03/30 20:59:04 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"
#include "../../libunit/framework/includes/libunit.h"
#include "../../../include/minishell.h"

int test_space(void)
{
    if (get_token(' ') == ' ')
        return (0);
    else
        return (-1);
}

int test_tab(void)
{
    if (get_token('\t') == '\t')
        return (0);
    else
        return (-1);
}

int test_str(void)
{
	//t_tkntype s;
	//s = STR;
    if (get_token('d') == STR)
        return (0);
    else
        return (-1);
}

