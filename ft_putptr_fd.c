/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlu-bjor <wlu-bjor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 15:55:59 by wlu-bjor          #+#    #+#             */
/*   Updated: 2026/05/08 20:28:50 by wlu-bjor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_fd(unsigned long long n, int fd)
{
	int	result;

	result = 0;
	result += ft_putstr_fd("0x", 1);
	if (result < 0)
		return (-1);
	result += ft_putnbr_base16_fd(n, fd, 'a');
	if (result < (0 + 2))
		return (-1);
	return (result);
}
