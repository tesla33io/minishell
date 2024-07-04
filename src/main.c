/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:28:07 by astavrop          #+#    #+#             */
/*   Updated: 2024/07/04 22:20:29 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(void)
{
	t_shell_data *shell_data;

	shell_data = malloc(sizeof(t_shell_data));
	while (1)
	{
		init(shell_data);
		if (render_prompt(shell_data))
		{
			lexer(shell_data->lexer);
			printf("lexer done\n___________\n\n");
			ft_parse(shell_data, ft_strdup(COMPLETE_COMMAND), shell_data->ast->root, shell_data->lexer->head); 
		}
			//takeout_trash(shell_data);
	}
	return (0);
}

//init unmatched and matched in lexer and token
