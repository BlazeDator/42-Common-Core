/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 09:01:39 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/18 12:18:51 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_useless(t_node *node, int i)
{
	if (node->last_c == i && (i == 0 || i == 3 || i == 6))
		return (1);
	else if ((node->last_c == 1 && i == 2) || (node->last_c == 2 && i == 1)
		|| (node->last_c == 4 && i == 5) || (node->last_c == 5 && i == 4)
		|| (node->last_c == 7 && i == 8) || (node->last_c == 8 && i == 7)
		|| (node->last_c == 9 && i == 10) || (node->last_c == 10 && i == 9))
		return (1);
	return (0);
}
