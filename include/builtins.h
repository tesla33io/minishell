/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 20:15:30 by astavrop          #+#    #+#             */
/*   Updated: 2024/06/09 21:18:20 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "./execution.h"

int		echo_builtin(t_Command *echo);
int		pwd_builtin(t_Command *pwd);

#endif /* BUILTINS_H */
