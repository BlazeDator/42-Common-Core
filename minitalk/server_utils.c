/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:41:18 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/06 09:06:08 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_power(int n, int power)
{
	int	i;
	int	sum;

	i = 1;
	sum = 1;
	while (i <= power)
	{
		sum *= n;
		i++;
	}
	return (sum);
}

unsigned char	ft_bits_to_byte(char *bits)
{
	int	binary_power[8];
	int	i;
	int	power;
	int	sum;

	i = 0;
	sum = 0;
	power = 7;
	while (i < 7)
	{
		binary_power[i] = ft_power(2, power);
		i++;
		power--;
	}
	binary_power[i] = 1;
	i = 0;
	while (i < 8)
	{
		sum = sum + (bits[i] * binary_power[i]);
		i++;
	}
	return (sum);
}
