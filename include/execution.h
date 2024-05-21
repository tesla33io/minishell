/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:07:30 by astavrop          #+#    #+#             */
/*   Updated: 2024/05/21 20:15:08 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "../lib/libft/libft.h"

/* Macros to make ht access code more readable */
# define KEY 0
# define VALUE 1

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
void				generate_envp_ht(t_kv envp_ht[TABLE_SIZE], char **envpv);

/* Error utility functions */

int					fork_fail(void);
int					execve_fail(void);

#endif /* EXECUTION_H */
