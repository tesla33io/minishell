/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 20:15:30 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/14 21:26:24 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "./execution.h"

int		echo_builtin(t_command *echo);
int		pwd_builtin(t_command *pwd);
int		env_builtin(t_command *env);
int		export_builtin(t_command *exprt);

int		unset_builtin(t_command *unset);
int		remove_env_var(char **envp, char *var);

int		cd_builtin(t_command *cd);
int		exit_builtin(t_command *e);

#endif /* BUILTINS_H */
