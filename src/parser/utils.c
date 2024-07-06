/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 01:08:00 by ltreser           #+#    #+#             */
/*   Updated: 2024/07/06 01:09:52 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int contains_c(char *str, char c)
{   
    int i;
    
    i = 0;
    while (str[i])
    {   
        if (str[i] == c)
            return (1);
        i++;
    }
    return (0);
}

int is_upper(char c)
{   
    if (c >= 'A' && c <= 'Z')
           return (1);
    else
        return (0);
}

int is_lower(char c)
{   
    if (c >= 'a' & c <= 'z')
        return (1);
    else
        return (0);
}

char *capitalize(char *str)
{
    int i;

    i = -1;
    while (str[++i])
        if (islower(str[i]))
            str[i] += 32;
    return (str);
}

