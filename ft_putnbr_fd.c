/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlu-bjor <wlu-bjor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 12:03:02 by wlu-bjor          #+#    #+#             */
/*   Updated: 2026/05/08 20:30:21 by wlu-bjor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base16_fd(unsigned long n, int fd, char base)
{
	int		result;
	char	number;

	result = 1;
	if (n < 16)
	{
		number = write_base16(n, base);
		ft_putchar_fd(number, fd);
		return (result);
	}
	number = write_base16(n % 16, base);
	result += ft_putnbr_base16_fd(n / 16, fd, base);
	ft_putchar_fd(number, fd);
	return (result);
}

int	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	int		result;
	char	number;

	result = 1;
	if (n < 10)
	{
		number = n + '0';
		ft_putchar_fd(number, fd);
		return (result);
	}
	number = (n % 10) + '0';
	result += ft_putnbr_unsigned_fd(n / 10, fd);
	ft_putchar_fd(number, fd);
	return (result);
}

// writes number at file descriptor 'fd'
int	ft_putnbr_fd(int n, int fd)
{
	char	number;
	int		result;

	result = 1;
	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	if (n < 0)
	{
		n = -n;
		ft_putchar_fd('-', fd);
		result++;
	}
	if (n <= 9)
	{
		number = n + '0';
		ft_putchar_fd(number, fd);
		return (result);
	}
	number = (n % 10) + '0';
	result += ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(number, fd);
	return (result);
}
