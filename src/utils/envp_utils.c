/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:42:30 by astavrop          #+#    #+#             */
/*   Updated: 2024/05/20 19:56:12 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"

char	**generate_envpv(t_kv envp_ht[ENVP_HT_SIZE])
{
	char	**envpv;
	int		envp_size;
	char	**envp_keys;

	envp_size = ht_len(envp_ht);
	envp_keys = ht_get_keys(envp_ht);
	if (!envp_keys)
		return (NULL);
	envpv = ft_malloc(NULL, sizeof(*envpv) * envp_size);
	if (!envpv)
		return (NULL);
	
}
