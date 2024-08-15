/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:58:00 by ltreser           #+#    #+#             */
/*   Updated: 2024/08/15 18:06:59 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include <stdio.h>

char	*ft_chop(char *str, char c)
{
	int		i;
	int		len;
	char	*chop;

	i = 0;
	len = 0;
	chop = NULL;
	while (str[len] && str[len] != c)
		len++;
	chop = gc_malloc((len + 1) * sizeof(char));
	while (str[i] && i < len)
	{
		chop[i] = str[i];
		i++;
	}
	chop[i++] = '\0';
	len = i;
	i = 0;
	ft_memmove(str, str + len, (ft_strlen(str) - len));
	ft_bzero(str + (ft_strlen(str) - len), len);
	return (chop);
}

char	*contains_terminal(char *production)
{
	int	i;
	int	len;
	int	word;

	i = -1;
	len = 0;
	word = 0;
	while (production[++i])
	{
		if (is_lower(production[i]) && word)
			word--;
		else if (word || (is_upper(production[i]) && ++word))
			len++;
	}
	if (!len)
		return (NULL);
	i = -1;
	while (production[++i] && !is_upper(production[i]))
		;
	return (ft_substr(production, i, len));
}

char	*contains_non_terminal(char *production)
{
	int	i;
	int	len;
	int	word;

	i = -1;
	len = 0;
	word = 0;
	while (production[++i])
	{
		if (is_upper(production[i]) && word)
			word--;
		else if (word || (is_lower(production[i]) && ++word))
			len++;
	}
	if (!len)
		return (NULL);
	i = -1;
	while (production[++i] && !is_lower(production[i]))
		;
	return (ft_substr(production, i, len));
}
