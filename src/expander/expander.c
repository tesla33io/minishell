#include "../../include/minishell.h"

//! if variable name not found, its just a normal str
//names of variables are sequences of letters, numbers and underscores
//the first symbol cant be a digit
//$? is not an environment variable but still needs to be expanded
//heredocs are also being expanded

//TODO
//extract name
//loop through env vars and check if matching
//if no match, replace non-ascii char with $ and continue
//if matching, insert the expansion result into the correct place of the str
//keep looping for potential further expansions
//write the ft that replaces $ with non ascii when needed and 


void	var_expand(char *str)
{
	int i;

	i = 0;
	while (str[i])
		if (str[i] == '$') //insert here the non ascii char instea,d write replacer ft first
		{
				
