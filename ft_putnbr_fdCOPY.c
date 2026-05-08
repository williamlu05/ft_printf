/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlu-bjor <wlu-bjor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 12:03:02 by wlu-bjor          #+#    #+#             */
/*   Updated: 2026/05/08 20:19:18 by wlu-bjor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base16_fd(unsigned long long n, int fd, char base)
{
	int		result;
	char	number;
	int		temp;

	result = 1;
	if (n < 16)
		return (ft_putchar_fd(write_base16(n, base), fd));
	number = write_base16(n % 16, base);
	temp = ft_putnbr_base16_fd(n / 16, fd, base);
	if (temp < 0)
		return (-1);
	result += temp;
	temp = ft_putchar_fd(number, fd);
	if (temp < 0)
		return (-1);
	return (result + temp);
}

int	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	int		result;
	char	number;
	int		temp;

	result = 1;
	if (n < 10)
		return (ft_putchar_fd(n + '0', fd));
	number = (n % 10) + '0';
	temp = ft_putnbr_unsigned_fd(n / 10, fd);
	if (temp < 0)
		return (-1);
	result += temp;
	temp = ft_putchar_fd(number, fd);
	if (temp < 0)
		return (-1);
	return (result + temp);
}

int	base_cases(int *n, int fd)
{
	if (*n < 0)
	{
		*n = -1 * (*n);
		return (ft_putchar_fd('-', fd));
	}
	if (*n <= 9)
		return (ft_putchar_fd(*n + '0', fd));	
	return (0);	
}

// writes number at file descriptor 'fd'
int	ft_putnbr_fd(int n, int fd)
{
	char	number;
	int		result;
	int		temp;

	result = 1;
	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	temp = base_cases(&n, fd);
	if (temp < 0)
		return (-1);
	number = (n % 10) + '0';
	temp =  ft_putnbr_fd(n / 10, fd);
	if (temp < 0)
		return (-1);
	result += temp;
	temp = ft_putchar_fd(number, fd);
	if (temp < 0)
		return (temp);
	return (result + temp);
}
