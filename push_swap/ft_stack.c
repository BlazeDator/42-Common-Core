/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:20:03 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/08 14:22:31 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_new(int num)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->num = num;
	new->next = 0;
	return (new);
}

void	ft_stack_clear(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}

int	ft_stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

void	ft_stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*temp;

	if (stack[0])
	{
		temp = stack[0];
		while (stack[0]->next)
			stack[0] = stack[0]->next;
		stack[0]->next = new;
		stack[0] = temp;
	}
	else
		stack[0] = new;
}

void	ft_stack_add_front(t_stack **stack, t_stack *new)
{
	new->next = stack[0];
	stack[0] = new;
}
