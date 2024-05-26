/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:07:30 by astavrop          #+#    #+#             */
/*   Updated: 2024/05/26 21:07:28 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "../lib/libft/libft.h"

/* Macros to make ht access code more readable */
# define KEY 0
# define VALUE 1
# define RD 0
# define WR 1

typedef struct s_Ast t_Ast;
typedef union u_AstNode t_AstNode;
typedef struct s_Command t_Command;
typedef struct s_Pipeline t_Pipeline;

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

struct	s_Pipeline
{
	t_AstNode	**commands; // TODO: find a better name
	int			num_cmds;
};


enum	e_AstNodeType
{
	COMMAND,
	PIPELINE,
	REDIRECTION,
	L_AND,
	L_OR
};

typedef enum e_AstNodeType t_AstNodeType;

union	u_AstNode
{
	t_Command		command;
	t_Pipeline		pipeline;
};


struct	s_Ast
{
	t_AstNodeType	node_type;
	t_AstNode		node;
};

/* Core functions */

void				execute_command_in_child(t_Command *command, int pipefd[2][2]);

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
void				print_cmd(t_Command *cmd);

/* DELETE */
void				print_strarray(char **arr);
void				print_hashtable(t_kv ht[TABLE_SIZE]);

#endif /* EXECUTION_H */
