/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:34:55 by astavrop          #+#    #+#             */
/*   Updated: 2024/04/28 19:02:37 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/executor.h"
#include "../../include/builtins.h"
#include "../../lib/libft/libft.h"

t_kv	*setup_builtin_hashtable(void)
{
	static t_kv	ht[TABLE_SIZE];

	ht_set(ht, "echo", ft_echo);
	ht_set(ht, "cd", ft_cd);
	ht_set(ht, "pwd", ft_pwd);
	ht_set(ht, "export", ft_export);
	ht_set(ht, "unset", ft_unset);
	ht_set(ht, "env", ft_env);
	// ht_set(ht, "exit", ft_exit); <- not ready yet
	return (ht);
}

int	execute_builtin(t_SimpleCommand *cmd, t_kv ht[TABLE_SIZE])
{
	void	*bfunc;

	bfunc = ht_get(ht, cmd->bin);
	if (!bfunc)
		return (-1);
	// bfunc();
}
