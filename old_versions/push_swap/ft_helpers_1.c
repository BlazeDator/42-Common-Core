/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:34:35 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/17 09:06:57 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_atoi(int num, char *str)
{
	char	*numstr;

	numstr = ft_itoa(num);
	if (ft_strncmp(numstr, str, ft_strlen(str)))
	{
		free(numstr);
		return (0);
	}
	free(numstr);
	return (1);
}

int	ft_stack_duplicates(t_stack *stack, int num)
{
	while (stack)
	{
		if (stack->number == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	ft_stack_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->number > stack->next->number)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

int	ft_node_final(t_node *node, int max_value)
{
	while (node)
	{
		if (node->value == max_value && ft_stack_size(node->b) == 0)
		{
			//ft_node_display_one(node);
			ft_printf("%s", node->commands);
			return (1);
		}
		node = node->next;
	}
	return (0);
}
