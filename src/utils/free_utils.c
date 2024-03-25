/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:33:20 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/20 16:33:20 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/executor.h"
#include "../../lib/libft/libft.h"
#include <stdlib.h>
#include <unistd.h>

void	free_str_list(char	**lst)
{
	int	i;

	i = -1;
	if (!lst)
		return ;
	while (lst[++i])
		ft_free_ptr(lst[i]);
	ft_free_ptr(lst);
}

void	free_cmd(t_SimpleCommand *cmd)
{
	ft_free_ptr(cmd->bin);
	free_str_list(cmd->args);
	free_str_list(cmd->in_fs);
	free_str_list(cmd->out_fs);
	if (cmd->pipefd[0] > 2)
		close(cmd->pipefd[0]);
	if (cmd->pipefd[1] > 2)
		close(cmd->pipefd[1]);
	ft_free_ptr(cmd);
}
