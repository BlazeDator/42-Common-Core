/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:22:43 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/07 12:41:12 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_push(t_stack **dest, t_stack **src, char name)
{
	t_stack	*temp_src;

	if (ft_stack_size(src[0]))
	{
		temp_src = src[0];
		src[0] = src[0]->next;
		temp_src->next = dest[0];
		dest[0] = temp_src;
	}
	if (name)
		ft_printf("p%c\n", name);
}
