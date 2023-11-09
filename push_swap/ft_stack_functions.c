/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:25:30 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/09 10:36:34 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_stack_swap(t_stack **stack, char *name)
{
	t_stack	*temp;

	if (ft_stack_size(stack[0]) > 1)
	{
		temp = stack[0];
		stack[0] = stack[0]->next;
		temp->next = stack[0]->next;
		stack[0]->next = temp;
	}
	if (name)
		return (ft_strdup(name));
	return (0);
}

char	*ft_stack_push(t_stack **dest, t_stack **src, char *name)
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
		return (ft_strdup(name));
	return (0);
}

char	*ft_stack_rotate(t_stack **stack, char *name)
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
		return (ft_strdup(name));
	return (0);
}

char	*ft_stack_reverse_rotate(t_stack **stack, char *name)
{
	t_stack	*temp;
	t_stack	*runner;

	if (ft_stack_size(stack[0]) > 1)
	{
		runner = stack[0];
		while (runner->next->next)
			runner = runner->next;
		temp = runner->next;
		runner->next = 0;
		temp->next = stack[0];
		stack[0] = temp;
	}
	if (name)
		return (ft_strdup(name));
	return (0);
}
