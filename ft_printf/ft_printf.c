/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:28:19 by pabernar          #+#    #+#             */
/*   Updated: 2023/10/18 11:37:37 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += ft_typefinder(str[i], args);
		}
		else
		{
			write(1, &str[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count); 
}
/*
int	main(void)
{
	int	count;

	count = ft_printf("%c, %%testes %s", '1', "12345");
	ft_printf("\ncount of last sentence: %i\n", count);
	ft_printf("\t count: %i\n", ft_printf("NULL %s NULL", 0));
	ft_printf("\t count: %i\n", ft_printf(" %p %p ", 0, 0));
	ft_printf("\t count: %i\n", ft_printf("%i", 2147483647));
	ft_printf("\t\t count: %d\n", ft_printf("%i", -101));
	ft_printf("\t count: %i\n", ft_printf("%i", -2147483648));
	ft_printf("\t count: %i\n", ft_printf("%u", 4294967295));
	ft_printf("\t\t count: %i\n", ft_printf("%x", 255));
	ft_printf("\t count: %i\n", ft_printf("%X", 2147483647));
	ft_printf("\t count: %i\n", ft_printf("%p", &"ola"));
	ft_printf("\t\t count: %i\n", ft_printf("%p", 0));
	return (0);
}*/
