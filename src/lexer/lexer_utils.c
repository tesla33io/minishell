#include "minishell.h"

int	find_match(char *str, char c)
{
	int i;

	i = 1;
	if (!str)
		return (0);
	if (!str[1])
		return (0);
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (i);
	else
		return (0);
}
