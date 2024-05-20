/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:07:30 by astavrop          #+#    #+#             */
/*   Updated: 2024/05/20 18:38:24 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "../lib/libft/libft.h"

# define ENVP_HT_SIZE 100

enum	e_CommandType
{
	EXTERNAL,
	BUILTIN
};

struct	s_Command
{
	e_CommandType	type;
	char			*bin_name;
	char			**args;
	t_kv			envp_ht[ENVP_HT_SIZE];
	int				in_fd;
	int				out_fd;
};

typedef struct s_Command t_Command;

/* Error utility functions */

int					fork_fail(void);
int					execve_fail(void);

#endif /* EXECUTION_H */
