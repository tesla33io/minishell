/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 20:59:52 by astavrop          #+#    #+#             */
/*   Updated: 2024/04/28 19:08:24 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <stdbool.h>
# include <stddef.h>

# include "executor.h"

void	ft_echo(t_SimpleCommand *cmd);
void	ft_cd(t_SimpleCommand *cmd);
void	ft_pwd(t_SimpleCommand *cmd);
void	ft_env(t_SimpleCommand *cmd);
void	ft_export(char *key, char *value, char **envp[]);
void	ft_unset(char *name, char **envp[]);

/* Utils */

void	free_envp(char *envp[]);
char	*create_kv_entry(char *key, char *value);
bool	envp_contains(char *key, char *envp[]);
int		envp_keycmp(char *key, char *envp_entry, size_t key_len);
char	*ft_getenv(char *envp[], char *name);

#endif
