/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:28:19 by pabernar          #+#    #+#             */
/*   Updated: 2023/10/12 11:44:26 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// p unsigned long / xX unsignd int

int	ft_printf(const char *str, ...)
{
	va_list args;

	va_start(args, str);
	// int i = va_arg(args, int); converte o valor atual em int e grava na variavel i


	va_end(args);
	return (0); //number of characters printed
}
