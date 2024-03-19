/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:50:05 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/19 22:50:10 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

typedef struct s_SimpleCommand
{
	char	*bin;
	char	*args[];
	char	*in_fs[];
	char	*out_fs[];
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
	t_Type			type;
	t_SimpleCommand	*cmd;
	t_CommandNode	*left;
	t_CommandNode	*right;
}	t_CommandNode;

#endif
