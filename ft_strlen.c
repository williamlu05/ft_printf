/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlu-bjor <wlu-bjor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 15:55:08 by wlu-bjor          #+#    #+#             */
/*   Updated: 2026/05/05 16:59:41 by wlu-bjor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

// Returns length of string 's'
int	ft_strlen(const char *s)
{
	int	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

/*
int main(void){
    printf("%li, ", ft_strlen("hola"));
    printf("%li, ", ft_strlen("holaqwdouqbd"));
    printf("%li, ", ft_strlen(""));
    printf("%li, ", ft_strlen("h"));
}
*/