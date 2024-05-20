/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:07:30 by astavrop          #+#    #+#             */
/*   Updated: 2024/05/20 22:13:07 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "../lib/libft/libft.h"

enum	e_CommandType
{
	EXTERNAL,
	BUILTIN
};

typedef enum e_CommandType t_CommandType;

struct	s_Command
{
	t_CommandType	type;
	char			*bin_name;
	char			**args;
	t_kv			envp_ht[TABLE_SIZE];
	char			**envpv;
	int				in_fd;
	int				out_fd;
};

typedef struct s_Command t_Command;

/* Helper functions */

char				**generate_envpv(t_kv envp_ht[TABLE_SIZE]);

/* Error utility functions */

int					fork_fail(void);
int					execve_fail(void);

#endif /* EXECUTION_H */
