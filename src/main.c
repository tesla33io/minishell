/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:28:07 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/30 23:14:51 by astavrop         ###   ########.fr       */
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
		render_prompt(shell_data);
		lexer(shell_data->lexer);
		//takeout_trash(shell_data);
	}
	return (0);
}
