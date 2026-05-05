/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlu-bjor <wlu-bjor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 23:19:04 by wlu-bjor          #+#    #+#             */
/*   Updated: 2026/05/05 13:05:19 by wlu-bjor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char const	*write_until(char const *format, char letter);
void	interpret_conversion(char const *format, va_list *args);

int	pos_of(char const *format, char c, int iter)
{
	while (format[iter] != c)
		iter++;
	return (iter);
}

int	ft_num_occ_conversions(char const *format)
{
	int	result;
	int	i;

	result = 0;
	i = pos_of(format, '%', 0);
	while (format[i])
	{
		i++;
		result++;
		if (format[i + 1] == '%')
			i++;
		i = pos_of(format, '%', i);
	}
	return (result);
}

int	ft_printf(char const *format, ...)

{
	int		num_args;
	va_list	args;
	int		i;

	num_args = ft_num_occ_conversions(format);
	va_start(args, format);

	i = 0;
	while (i < num_args)
	{
		format = write_until(format, '%');
		if (format)
			interpret_conversion(format, &args);
		i++;
	}
	return (1);
}

#include <stdio.h>
int main(void)// int argc, char **argv
{
	ft_printf("estoy hablando conl a persona %i", 10);
	printf("\n");
	printf("estoy hablando conl a persona %i", 10);
}



/*
PLANNING:

printf returns the number of characters printed on screen
- Any errors returns a negative value

1. Call a function that finds the number of '%' found (maybe loop of ft_strchr),
2. Initiate the args with va_start, with the number of '%' found
3. Loop over the linked list, and pass the type depending on what was stored of "cspdiuxX%"
4. Have the function write up until that instance of '%', 
	and then write what was in the argument, how it is written varies on the type
5. 

Things to remember:
- Freeing all of the allocated space used with the auxilliary linked list,
	both in a correct or failed execution
- You can use the comparisons with the original printf():
	"La función se comparará con el printf() original para verificar su comportamiento."
- 
*/