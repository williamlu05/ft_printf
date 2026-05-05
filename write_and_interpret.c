/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_and_interpret.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlu-bjor <wlu-bjor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 11:47:55 by wlu-bjor          #+#    #+#             */
/*   Updated: 2026/05/05 13:04:53 by wlu-bjor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
	Writes all characters up to 'letter' and returns 
	the string 'format' pointed to the char after 'letter'
*/

void	interpret_conversion(char const *format, va_list *args)
{
	if (*format == 'c' || *format == '%')
		ft_putchar_fd(va_arg(*args, int), 1);
	else if (*format == 's')
		ft_putstr_fd(va_arg(*args, char *), 1);
	else if (*format == 'p')
	{
		
	}
	else if (*format == 'd')
		ft_putnbr_fd(va_arg(*args, int), 1);
	else if(*format == 'i')
		ft_putnbr_fd(va_arg(*args, unsigned int), 1);
	else if (*format == 'x'){}
		//ft_putnbr_base_fd(va_arg(*args, int), 16, 'a', 1);
	else if (*format == 'X'){}
		//ft_putnbr_base_fd(va_arg(*args, int), 16, 'A', 1);
}

char const	*write_until(char const *format, char letter)
{
	int	i;

	i = 0;
	if (format[i] != letter)
		ft_putchar_fd(format[i++], 1);
	if (format[i] == letter)
		return (format + i + 1);
	return (NULL);
}
