/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tokens2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 20:38:55 by ltreser           #+#    #+#             */
/*   Updated: 2024/03/30 21:11:57 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"
#include "../../libunit/framework/includes/libunit.h"
#include "../../../include/minishell.h"

int test_doublequotes(void)
{
    if (get_token('"') == '"')
        return (0);
    else
        return (-1);
}

int test_singlequotes(void)
{
    if (get_token('\'') == '\'')
        return (0);
    else
        return (-1);
}

int test_asterisk(void)
{
    if (get_token('*') == '*')
        return (0);
    else
        return (-1);
}

int test_comparison(void)
{
    if ((get_token('>') == '>') && (get_token('>') == '>'))
        return (0);
    else
        return (-1);
}

