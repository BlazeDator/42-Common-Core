/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:26:15 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/17 09:01:15 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_new(int num)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->number = num;
	new->next = 0;
	return (new);
}

t_stack	*ft_stack_add_front(t_stack *stack, t_stack *new)
{
	if (stack && new)
	{
		new->next = stack;
		return (new);
	}
	else if (new)
		return (new);
	return (0);
}

t_stack	*ft_stack_add_back(t_stack *stack, t_stack *new)
{
	t_stack	*start;

	start = 0;
	if (stack && new)
	{
		start = stack;
		while (stack->next)
			stack = stack->next;
		stack->next = new;
		return (start);
	}
	else if (new)
		return (new);
	return (0);
}

t_stack	*ft_stack_from_argv(char **argv, int mode)
{
	t_stack	*new;
	int		i;
	int		num;

	i = mode;
	num = 0;
	new = 0;
	while (argv[i])
	{
		num = ft_atoi(argv[i]);
		if (!ft_check_atoi(num, argv[i]) || ft_stack_duplicates(new, num))
		{
			if (new)
				ft_stack_free(new);
			return (0);
		}
		new = ft_stack_add_back(new, ft_stack_new(num));
		i++;
	}
	return (new);
}

int	ft_stack_free(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
	return (0);
}
