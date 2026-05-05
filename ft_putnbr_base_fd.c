/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlu-bjor <wlu-bjor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 15:10:19 by wlu-bjor          #+#    #+#             */
/*   Updated: 2026/05/05 17:37:55 by wlu-bjor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	pow_of(int base, int power)
{
	if (power <= 0)
		return (1);
	return (base * pow_of(base, power - 1));
}

// writes unsigned 
int ft_putnbr_unsigned_fd(unsigned long long n, int base, char start, int fd)
{
	char	number;
	int		result;

	result = 1;
	if (n <= 9)
	{
		number = n + start;
		write(fd, &number, 1);
		return (result);
	}
	number = (n % base) + start;
	result += ft_putnbr_unsigned_fd(n / base, base, start, fd);
	write(fd, &number, 1);
	return (result);
}

int	ft_putnbr_base16_fd(long long n, char start, int fd)
{
	char	number;
	int		result;

	result = 1;
	if (n < 0)
	{
		n = pow_of(2, sizeof(unsigned long long) * 8) + n;
		result++;
	}
	if (n <= 9)
	{
		number = n + start;
		write(fd, &number, 1);
		return (result);
	}
	number = (n % 16) + start;
	result += ft_putnbr_fd(n / 16, fd);
	write(fd, &number, 1);
	return (result);
}