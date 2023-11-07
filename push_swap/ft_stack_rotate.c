/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:48:48 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/07 13:01:33 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_rotate(t_stack **stack, char name)
{
	t_stack	*temp;
	t_stack	*runner;

	if (ft_stack_size(stack[0]) > 1)
	{
		temp = stack[0];
		stack[0] = stack[0]->next;
		runner = stack[0];
		while (runner->next)
			runner = runner->next;
		runner->next = temp;
		temp->next = 0;
	}
	if (name)
		ft_printf("r%c\n", name);
}
