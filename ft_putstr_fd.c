/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlu-bjor <wlu-bjor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 12:00:12 by wlu-bjor          #+#    #+#             */
/*   Updated: 2026/05/05 16:59:41 by wlu-bjor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

// Writes string 's' at file descriptor 'fd'
int	ft_putstr_fd(char *s, int fd)
{
	int	result;
	
	if (!s || fd < 0)
		return (0);
	result = ft_strlen(s);
	write(fd, s, result);
	return (result);
}
