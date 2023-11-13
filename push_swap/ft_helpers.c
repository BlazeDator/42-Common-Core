/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:34:35 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/13 11:12:48 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_atoi(int num, char *str)
{
	int	str_len;
	int	temp;

	temp = 0;
	str_len = ft_strlen(str);
	if ((str[0] != '0' && num == 0)
		|| (str[0] == '-' && num > 0) || (str[0] == '-' && str_len > 11)
		|| (str[0] != '-' && num < 0) || (str[0] != '-' && str_len > 10))
		return (0);
	str_len--;
	if (str[0] == '-')
		temp = -1;
	else
		temp = 1;
	while (str_len > 0)
	{
		if (str_len == 0 && str[str_len] == '-')
			break ;
		if ((str[str_len] - '0') != (num % 10 * temp))
			return (0);
		num /= 10;
		str_len--;
	}
	return (1);
}
