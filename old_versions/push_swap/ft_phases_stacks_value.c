/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phases_stacks_value.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:38:00 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/18 10:41:11 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_phase_one_stacks_value(t_stack *a, t_stack *b)
{
	int	value;

	value = 0;
	while (a && a->next)
	{
		if (a->number < a->next->number)
			value += 1;
		a = a->next;
	}
	while (b && b->next)
	{
		if (b->number > b->next->number)
			value += 2;
		b = b->next;
	}
	return (value);
}
