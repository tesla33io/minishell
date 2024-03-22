/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:27:59 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/22 23:02:04 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <curses.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "../../lib/ft_printf/includes/ft_printf.h"
#include "../../lib/libft/libft.h"


typedef struct s_lex t_lex;
typedef struct s_token t_token;

enum	e_tkntype
{
	DOLARSIGN,
	AMPERSAND,
	QUESTIONMARK,
	PIPE,
	L_PARENTHESIS,
	R_PARENTHESIS,
	D_QUOTE,
	S_QUOTE,
	ASTERISK,
	GREATER_THAN,
	LESS_THAN,
	SPACE,
	STR,
}

struct s_token
{
	e_tkntype	token;
	char		*lexeme;
	t_token 	*next;
	t_token		*prev;
} ;

struct s_lex
{
	t_token	*start;
	char	*command_line;
} ;

int		render_prompt(void);

#endif
