/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 20:15:30 by astavrop          #+#    #+#             */
/*   Updated: 2024/06/24 21:39:22 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "./execution.h"

int		echo_builtin(t_Command *echo);
int		pwd_builtin(t_Command *pwd);
int		env_builtin(t_Command *env);
int		export_builtin(t_Command *exprt);
int		unset_builtin(t_Command *unset);
int		cd_builtin(t_Command *cd);

#endif /* BUILTINS_H */
