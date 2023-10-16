/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:28:19 by pabernar          #+#    #+#             */
/*   Updated: 2023/10/16 14:54:23 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// %p unsigned long / %x %X unsignd int
// int i = va_arg(args, int); converte o valor atual em int e grava na variavel i

int	ft_printf(const char *str, ...)
{
	va_list args;
	int	i;
	int	count;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i++] == '%')
			count += ft_typefinder(str[i++], args);
		else
			write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (count); //number of characters printed
}

int	main(void)
{
	ft_printf("%i", 2147483647);
	return (0);
}
