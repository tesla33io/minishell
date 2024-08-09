/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:23:06 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/09 16:36:00 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

// General
int			ft_dprintf(int fd, const char *format, ...);
int			print(int fd, const char *s, va_list arg);

// Formaters
int			formatter_c(char c, int count, int fd);
int			formatter_s(char *s, int count, int fd);
int			formatter_di(int n, int count, int fd);
int			formatter_u(unsigned int n, int count, int fd);
int			formatter_x(unsigned int x, int count, int upper, int fd);
int			formatter_ptr(void *ptr, int count, int fd);

// Additional
int			numlen(long int n);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(long int n, int fd);
void		ft_putstr_fd(char *s, int fd);
int			ft_strlen(const char *s);
char		*ft_strdup(const char *s);

#endif // !FT_PRINTF_H
