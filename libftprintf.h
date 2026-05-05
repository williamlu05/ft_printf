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

# include "./libft/libft.h"
# include <stdarg.h>

int	ft_printf(char const *, ...);
char const	*write_until(char const *format, char letter);
void	interpret_conversion(char const *format, va_list *args);



#endif