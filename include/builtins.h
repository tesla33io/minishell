/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 20:59:52 by astavrop          #+#    #+#             */
/*   Updated: 2024/04/20 14:48:04 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <stdbool.h>

void	ft_echo(int fd, int ac, char **av);
void	ft_cd(const char *path);
void	ft_pwd(void);
void	ft_env(char *envp[]);
void	ft_export(char *name, char *value, char **envp[]);

/* Utils */

void	free_envp(char *envp[]);
char	*create_kv_entry(char *name, char *value);
bool	envp_contains(char *name, char *envp[]);

#endif
