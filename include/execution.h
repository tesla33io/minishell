/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:07:30 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/01 23:10:10 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "../lib/libft/libft.h"

# include <stdbool.h>

# define RD 0
# define WR 1

typedef struct s_Command	t_Command;
typedef struct s_Pipeline	t_Pipeline;

enum	e_CommandType
{
	EXTERNAL,
	BUILTIN
};

typedef enum e_CommandType	t_CommandType;

struct	s_Command
{
	char			*bin_name;
	char			**args;
	char			**envpv;
	int				in_fd;
	int				out_fd;
	bool			append;
	bool			heredoc;
};

struct	s_Pipeline
{
	t_Command	**commands;
	int			num_cmds;
};

/* Core functions */

void				execute_command_in_child(t_Command *cmd,
						int pipefd[2][2], int i, int num_cmds);
int					execute_pipeline(t_Pipeline *pipeline);
int					start_heredoc(const char *del);

/* Helper functions */

char				*ft_getenv(char **envp, char *name);
char				*check_exec_binary(char *path, char *bin_name);
int					is_builtin(char *bin_name);
int					run_builtin(t_Command *cmd);

/* Error utility functions */

int					fork_fail(void);
int					execve_fail(void);
int					cmd_not_found(char *name);

/* Misc functions */

char				*ft_path_join(char *path1, char *path2);

#endif /* EXECUTION_H */
