/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 20:59:52 by astavrop          #+#    #+#             */
/*   Updated: 2024/05/10 18:18:16 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <stdbool.h>
# include <stddef.h>

# include "../lib/libft/libft.h"
# include "executor.h"

void	ft_echo(t_SimpleCommand *cmd);
void	ft_cd(t_SimpleCommand *cmd);
void	ft_pwd(t_SimpleCommand *cmd);
void	ft_env(t_SimpleCommand *cmd);
void	ft_env_sorted(t_kv envp_ht[TABLE_SIZE]);
// void	ft_export(char *key, char *value, char **envp[]);
void	ft_export(t_SimpleCommand *cmd);
// char	**ft_export(t_SimpleCommand *cmd);
void	ft_unset(char *name, char **envp[]);

/* Utils */

// char	**ft_envdup(char *envp[]);
void	ft_envdup(t_kv envp_ht[TABLE_SIZE], char *envp[]);
void	free_envp(char *envp[]);
char	*create_kv_entry(char *key, t_kv envp_ht[TABLE_SIZE]);
char	**envp_ht_to_str_array(t_kv envp_ht[TABLE_SIZE]);
bool	envp_contains(char *key, char *envp[]);
int		envp_keycmp(char *key, char *envp_entry, size_t key_len);
char	*ft_getenv(char *envp[], char *name);
void	ft_strquicksort(char const *arr[], unsigned int length);
char	**ft_split_name_value(char const *s);

#endif
