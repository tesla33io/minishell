/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:00:39 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/31 00:04:35 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif // !BUFFER_SIZE

# include "../../libft/libft.h"

char		*get_next_line(int fd);

#endif
