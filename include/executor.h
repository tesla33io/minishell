/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:50:05 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/29 22:11:18 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

typedef struct s_SimpleCommand
{
	char	*bin;
	char	**args;
	char	**envp;
	char	**in_fs;
	char	**out_fs;
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

/* HOLY EXECUTOR Functions */

void	find_bin(t_SimpleCommand *cmd);
int		cmd_exe(t_SimpleCommand *cmd);
int		process_pipe(t_CommandNode *pipen);

/* Util functions */

void	free_str_list(char	**lst);
void	free_cmd(t_SimpleCommand *cmd);

/* OnError functions */

int		pipe_fail(int pipefd[2]);
int		execution_fail(char *cmd_bin);
int		fork_fail(void);

t_SimpleCommand	*cmd_gen(char *bin, char **args, char **envp, char **in_fs,
		char **out_fs, int pipefd[2]); /* TODO: DELETE */
void	print_command(t_SimpleCommand	*cmd);

#endif
