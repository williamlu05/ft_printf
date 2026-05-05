/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlu-bjor <wlu-bjor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 12:03:02 by wlu-bjor          #+#    #+#             */
/*   Updated: 2026/05/05 16:59:41 by wlu-bjor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

// writes number at file descriptor 'fd'
int	ft_putnbr_fd(int n, int fd)
{
	char	number;
	int		result;

	result = 1;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		n = -n;
		write(fd, "-", 1);
		result++;
	}
	if (n <= 9)
	{
		number = n + '0';
		write(fd, &number, 1);
		return (result);
	}
	number = (n % 10) + '0';
	result += ft_putnbr_fd(n / 10, fd);
	write(fd, &number, 1);
	return (result);
}
