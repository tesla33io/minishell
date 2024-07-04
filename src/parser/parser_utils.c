#include "minishell.h"

int	contains_c(char *str, char c)
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
char *ft_chop(char *str, char c)
{
	int i;
	int len;
	char *chop;
	
	i = 0;
	len = 0;
	while (str[len] && str[len] != c)
		len++;
	chop = malloc((len + 1) * sizeof(char));
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

int	is_upper(char c)
{
	if (c >= 'A' && c <= 'Z')
	       return (1);
	else
		return (0);
}

int	is_lower(char c)
{
	if (c >= 'a' & c <= 'z')
		return (1);
	else
		return (0);
}

char    *contains_terminal(char *production)
{
        int i;
        int len;
        char *terminal

        i = -1;
        len = 0;
        while (production[++i])
                if (is_upper(production[i]))
                        len++;
        if (len)
                terminal = malloc(len * sizeof(char));
        else
                return (NULL);
        i = -1;
        len = 0;
        while (production[++i])
                if (is_upper(production[i]) && len++)
                        terminal[i] = production[i];
        terminal[len] = '\0';
        return (terminal);
}

char *contains_non_terminal(char *production)
{
        int i;
        int len;
        char *non_terminal

        i = -1;
        len = 0;
        while (production[++i])
                if (is_lower(production[i]))
                        len++;
        if (len)
                non_terminal = malloc(len * sizeof(char));
        else
                return (NULL);
        i = -1;
        len = 0;
        while (production[++i])
                if (is_upper(production[i]) && len++)
                        non_terminal[i] = production[i];
        non_terminal[len] = '\0';
        return (non_terminal);
}

