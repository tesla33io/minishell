/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 20:59:52 by astavrop          #+#    #+#             */
/*   Updated: 2024/05/07 18:27:14 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <stdbool.h>
# include <stddef.h>

# include "../lib/libft/libft.h"
# include "executor.h"

# define ENVP_HT_SIZE 1000
# define BUILTIN_HT_SIZE 42

void	ft_echo(t_SimpleCommand *cmd);
void	ft_cd(t_SimpleCommand *cmd);
void	ft_pwd(t_SimpleCommand *cmd);
void	ft_env(t_SimpleCommand *cmd);
void	ft_env_sorted(char *envp[]);
// void	ft_export(char *key, char *value, char **envp[]);
void	ft_export(t_SimpleCommand *cmd);
// char	**ft_export(t_SimpleCommand *cmd);
void	ft_unset(char *name, char **envp[]);

/* Utils */

// char	**ft_envdup(char *envp[]);
void	ft_envdup(t_kv envp_ht[ENVP_HT_SIZE], char *envp[]);
void	free_envp(char *envp[]);
char	*create_kv_entry(char *key, char *value);
bool	envp_contains(char *key, char *envp[]);
int		envp_keycmp(char *key, char *envp_entry, size_t key_len);
char	*ft_getenv(char *envp[], char *name);
void	ft_strquicksort(char const *arr[], unsigned int length);
char	**ft_split_name_value(char const *s);

#endif
