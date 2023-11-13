/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:34:35 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/13 15:22:01 by pabernar         ###   ########.fr       */
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
