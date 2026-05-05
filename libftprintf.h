/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlu-bjor <wlu-bjor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 22:47:04 by wlu-bjor          #+#    #+#             */
/*   Updated: 2026/05/04 22:47:04 by wlu-bjor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(char const *, ...);
int	interpret_conversion(char const *format, va_list *args);

int	ft_strlen(const char *s);
int	ft_putstr_fd(char *s, int fd);
int	ft_putchar_fd(char c, int fd);

int	ft_putptr_fd(unsigned long long n, int fd);
int	ft_putnbr_fd(int n, int fd);
int ft_putnbr_unsigned_fd(unsigned long long n, int base, char start, int fd);
int	ft_putnbr_base16_fd(long long n, char start, int fd);

#endif