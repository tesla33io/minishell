/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:07:30 by astavrop          #+#    #+#             */
/*   Updated: 2024/05/25 17:25:41 by astavrop         ###   ########.fr       */
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

/* Core functions */

int					execute_command_in_child(t_Command *command);

/* Helper functions */

char				*ft_getenv(char **envp, char *name);
int					find_executable_on_path(char *path, char *bin_name);

/* DEPRECATED
char				**generate_envpv(t_kv envp_ht[TABLE_SIZE]);
void				generate_envp_ht(t_kv envp_ht[TABLE_SIZE], char **envpv);*/

/* Error utility functions */

int					fork_fail(void);
int					execve_fail(void);

/* Misc functions */
  
char				*ft_path_join(char *path1, char *path2);

/* DELETE */
void				print_strarray(char **arr);
void				print_hashtable(t_kv ht[TABLE_SIZE]);

#endif /* EXECUTION_H */
