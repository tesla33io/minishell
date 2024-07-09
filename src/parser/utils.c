/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 01:08:00 by ltreser           #+#    #+#             */
/*   Updated: 2024/07/09 19:32:58 by ltreser          ###   ########.fr       */
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
    if (c >= 'a' && c <= 'z')
        return (1);
    else
        return (0);
}

char *capitalize(char *str)
{
    int i;

    i = -1;
    while (str[++i])
        if (is_lower(str[i]))
            str[i] += 32;
    return (str);
}

t_tkntype       tok2int(char *symbol)
{
        int i;

        i = -1;
    const char* token_names[] = {"x", "x", "x", "x", "x", "x", "x", "x", "NNEWLINE", "TTAB", "x", "STR", "HEREDOC", "APPEND", "AND", "OR", "TRASH",  "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", [SSPACE] = "SSPACE", "x", [D_QUOTE] = "D_QUOTE", "x", "x", "x", [AMPERSAND] = "AMPERSAND", [S_QUOTE] = "S_QUOTE", [L_PARENTHESIS] = "L_PARENTHESIS", [R_PARENTHESIS] = "R_PARENTHESIS", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", [IN_REDIRECT] = "IN_REDIRECT", "x", [OUT_REDIRECT] = "OUT_REDIRECT", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", [PIPE] = "PIPE",
};
        while (++i < 125)
		if (!ft_strncmp(token_names[i], symbol, ft_strlen(token_names[i])))
			return (i);
        return (0);
}

int	count_words(char *s, char c)
{
	int	words;
	int	in_word;

	words = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == c)
			in_word = 0;
		else if (!in_word)
		{
			words++;
			in_word = 1;
		}
		s++;
	}
	return (words);
}
