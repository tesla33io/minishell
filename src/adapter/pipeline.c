/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:52:46 by astavrop          #+#    #+#             */
/*   Updated: 2024/07/24 19:24:11 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"
#include "../../include/minishell.h"

t_Pipeline	*extract_pipeline(t_leaf *pl_root)
{
	t_Pipeline	*pl;
	t_leaf		*next;
	(void)next;

	pl = gc_malloc(sizeof(*pl));
	if (!pl)
		return (NULL);
	pl->commands = gc_malloc(sizeof(t_Command *) * 2);
	pl->num_cmds = 2;
	pl->commands[0] = extract_command(pl_root->left);
	pl->commands[1] = extract_command(pl_root->right);
	return (pl);
}
