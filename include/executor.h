/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:50:05 by astavrop          #+#    #+#             */
/*   Updated: 2024/04/30 21:54:18 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include <stdbool.h>

typedef struct s_SimpleCommand
{
	char	*bin;
	char	**args;
	char	**envp;
	int		in_fd;
	int		out_fd;
	int		pipefd[2];
}	t_SimpleCommand;

typedef enum e_Type
{
	NONE,
	PIPE,
	AND,
	OR,
	CMD,
}	t_Type;

typedef struct s_CommandNode
{
	t_Type					type;
	t_SimpleCommand			*cmd;
	struct s_CommandNode	*left;
	struct s_CommandNode	*right;
}	t_CommandNode;

# define FAIL 1
# define SUCCESS 0
# define FATAL_ERROR -1

# define CNFOUND 127
# define NOXPERM 126

# define WREND 1
# define RDEND 0

/* HOLY EXECUTOR Functions */

void	find_bin(t_SimpleCommand *cmd);
int		cmd_exe(t_SimpleCommand *cmd, int mode);
int		process_pipe(t_CommandNode *pipen);

/* Executor utils */

int		bin_check(t_SimpleCommand *cmd, char *path);
int		cmd_check(t_SimpleCommand *cmd);

bool	is_builtint(char *bin, char *b_list[]);

/* Util functions */

void	free_str_list(char	**lst);
void	free_cmd(t_SimpleCommand *cmd);
int		w_check(int status);

/* OnError functions */

int		pipe_fail(int pipefd[2]);
int		execution_fail(char *cmd_bin);
int		fork_fail(void);

t_SimpleCommand	*cmd_gen(char *bin, char **args, char **envp, int in_fd,
		int out_fd, int pipefd[2]); /* TODO: DELETE*/

void	print_command(t_SimpleCommand	*cmd);

#endif
