/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:27:59 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/25 23:36:07 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../../lib/ft_printf/includes/ft_printf.h"
# include "../../lib/libft/libft.h"
# include <curses.h>
# include <dirent.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>

typedef struct s_lex		t_lex;
typedef struct s_token		t_token;
typedef struct s_shell_data	t_shell_data;
typedef enum e_tkntype t_tkntype;

enum						e_tkntype
{
	DOLARSIGN = '$',
	AMPERSAND = '&',
	QUESTIONMARK = '?',
	PIPE = '|',
	L_PARENTHESIS = '(',
	R_PARENTHESIS = ')',
	D_QUOTE = '"',
	S_QUOTE = '\'',
	ASTERISK = '*',
	GREATER_THAN = '>',
	LESS_THAN = '<',
	SSPACE = ' ',
	TTAB = '\t',
	STR,
};

struct						s_token
{
	enum e_tkntype			token;
	char					*lexeme;
	t_token					*next;
	t_token					*prev;
};

struct						s_lex
{
	t_token					*head;
	t_token					*tail;
	char					*cmd_line;
	int						start;
	int						end;
	int						tkn_count;
};

struct						s_shell_data
{
	t_lex					*lexer;
};

int							render_prompt(t_shell_data *shell_data);
void						init(t_shell_data *shell_data);
void						init_lexer(t_shell_data *shell_data);
void						lexer(t_lex *lexer);
void						append_token(t_lex *l, char *str, int len);
enum e_tkntype				get_token(char c);
int							special_char(char c);

#endif
