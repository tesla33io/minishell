/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:07:30 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/18 15:52:27 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "../lib/libft/libft.h"

# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>

# define MAX_N_FDS 1024
# define RD 0
# define WR 1
# define BUILTIN_FAILED "builtin failed to execute."

typedef struct s_Command	t_command;
typedef struct s_Pipeline	t_pipeline;

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
	t_command	**commands;
	int			num_cmds;
};

/* Core functions */

int					execute_command_in_child(t_command *cmd,
						int pipefd[2][2], int i, int num_cmds);
int					execute_pipeline(t_pipeline *pipeline);
int					start_heredoc(const char *del);

/* Helper functions */

char				*ft_getenv(char **envp, char *name);
char				**get_environment(char **envp);
char				*check_exec_binary(char *path, char *bin_name);
int					is_builtin(char *bin_name);
int					run_builtin(t_command *cmd);
void				setup_ipc(t_command *cmd, int i, int pipefd[2][2],
						int num_cmds);

/* Error utility functions */

int					fork_fail(void);
int					execve_fail(void);
int					builtin_failed(char *msg, char *func);
int					cmd_not_found(char *name);
void				*ret_null(char *msg, char *func, int line);
int					ret_int(char *msg, char *func, int line, int code);

/* Misc functions */

char				*ft_path_join(char *path1, char *path2);
unsigned char		set_last_exit_code(int code, int flag);
int					get_exit_code(pid_t pid);
int					close_extra_fds(void);
void				reset_signals(int flag);

#endif /* EXECUTION_H */
