/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlu-bjor <wlu-bjor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 15:55:59 by wlu-bjor          #+#    #+#             */
/*   Updated: 2026/05/05 16:59:41 by wlu-bjor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putptr_fd(unsigned long long n, int fd)
{
	int	result;

	result = 0;
	result += ft_putstr_fd("0x", 1);
	result += ft_putnbr_unsigned_fd(n, 10, '0', fd);
	return (result);
}
