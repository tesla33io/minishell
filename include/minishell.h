/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:27:59 by astavrop          #+#    #+#             */
/*   Updated: 2024/07/10 01:29:08 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../../lib/ft_printf/includes/ft_printf.h"
# include "../../lib/libft/libft.h"
# include "grammar.h"
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
typedef struct s_ast		t_ast;
typedef struct s_leaf		t_leaf;

enum						e_tkntype
{
	AMPERSAND = '&',
	PIPE = '|',
	L_PARENTHESIS = '(',
	R_PARENTHESIS = ')',
	D_QUOTE = '"',
	S_QUOTE = '\'',
	OUT_REDIRECT = '>',
	IN_REDIRECT = '<',
	SSPACE = ' ',
	TTAB = '\t',
	NNEWLINE = '\n',
	STR,
	HEREDOC,
	APPEND,
	AND,
	OR,
	TRASH,
};

typedef enum e_tkntype		t_tkntype;

struct						s_token
{
	enum e_tkntype			token;
	char					*lexeme;
	int						pair_token;
	int						matched;
	t_token					*next;
};

struct						s_lex
{
	t_token					*head;
	t_token					*tail;
	char					*cmd_line;
	int						start;
	int						end;
	int						tkn_count;
	int						unmatched;
};

struct						s_shell_data
{
	t_lex					*lexer;
	t_ast					*ast;
};

struct						s_ast
{
	t_leaf					*root;
	int						leafcount;
};

struct						s_leaf
{
	enum e_tkntype			token;
	char					*terminal;
	t_leaf					*parent;
	t_leaf					*left;
	t_leaf					*right;
};

int							render_prompt(t_shell_data *shell_data);
void						init(t_shell_data *shell_data);
void						init_lexer(t_shell_data *shell_data);
void						lexer(t_lex *lexer);
void						append_token(t_lex *lexer, char *str, int len,
								int backslash);
void						get_token_data(t_token *tok, char *str, int len,
								int backslash);
enum e_tkntype				get_token(char c);
int							special_char(char c);
int							find_match(char *str, char c);
void						merge_tokens(t_lex *lexer);
void						group_tokens(t_lex *lexer);
void						take_out_trash(t_token *head);
void						merge_strings(t_lex *lexer);
int							contains_c(char *str, char c);
char						*ft_chop(char *str, char c);
void						ft_parse(t_shell_data *shell_data, char *production, t_leaf **parent, t_token *token_stream);
int							is_upper(char c);
int							is_lower(char c);
void						print_tokens(t_lex *lexer);
char						*contains_non_terminal(char *production);
char						*contains_terminal(char *production);
t_tkntype					tok2int(char *symbol);
char						*capitalize(char *str);
t_leaf  *terminal_to_leaf(t_ast *ast, t_leaf *parent, t_token *token_stream);
t_leaf *append_leaf(t_leaf *leaf, t_leaf *parent, t_token *tok);
char *get_production(char *production);
int count_words(char *s, char c);
int count_tokens(t_token *head);


void	print_ast_leafs(t_leaf *l);

#endif
