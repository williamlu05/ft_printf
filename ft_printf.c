/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlu-bjor <wlu-bjor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 23:19:04 by wlu-bjor          #+#    #+#             */
/*   Updated: 2026/05/05 17:28:16 by wlu-bjor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		written;

	written = 0;
	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
			written += interpret_conversion(++format, &args);
		else
			written += ft_putchar_fd(*format, 1);
		format++;
	}
	va_end(args);
	return (written);
}


#include <stdio.h>
int main(void)// int argc, char **argv
{
	ft_printf("%i", ft_printf("estoy hablando con la persona %x: ", -10));
	printf("\n");

	//char string[20] = "hola";
	printf("%i", printf("estoy hablando con la persona %x: ", -10));
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