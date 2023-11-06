/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:41:27 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/06 09:05:58 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_byte_to_bits(unsigned char byte, unsigned char *bits)
{
	if (byte != 0)
		ft_byte_to_bits(byte / 2, bits - 1);
	*bits = byte % 2;
}
