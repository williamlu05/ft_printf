/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlu-bjor <wlu-bjor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 11:47:55 by wlu-bjor          #+#    #+#             */
/*   Updated: 2026/05/05 17:22:24 by wlu-bjor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
	Writes all characters up to 'letter' and returns 
	the string 'format' pointed to the char after 'letter'
*/
int	interpret_conversion(char const *format, va_list *args)
{
	if (*format == 'c' || *format == '%')
		return (ft_putchar_fd(va_arg(*args, int), 1));
	if (*format == 's')
		return (ft_putstr_fd(va_arg(*args, char *), 1));
	if (*format == 'p')
		return (ft_putptr_fd(va_arg(*args, unsigned long long), 1));
	if (*format == 'd')
		return (ft_putnbr_fd(va_arg(*args, int), 1));
	if (*format == 'i')
		return (ft_putnbr_fd(va_arg(*args, int), 1));
	if (*format == 'u')
		return (ft_putnbr_unsigned_fd(va_arg(*args, unsigned int), 10, '0', 1));
	if (*format == 'x')
		return (ft_putnbr_base16_fd(va_arg(*args, int), 'a', 1));
	if (*format == 'X')
		return (ft_putnbr_base16_fd(va_arg(*args, int), 'A', 1));
	return (0);
}
