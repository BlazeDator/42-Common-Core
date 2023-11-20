/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:57:57 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/20 16:04:17 by pabernar         ###   ########.fr       */
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

char	*ft_strjoin_f(char *commands, char *nstr)
{
	char	*temp;

	temp = ft_strjoin(commands, nstr);
	free(commands);
	return (temp);
}

int	ft_stack_pos(t_stack *stack, int num)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (num == stack->number)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (pos);
}

int	ft_stack_target(t_stack *stack, int num)
{
	while (stack)
	{
		if (num == stack->number)
			return (stack->target);
		stack = stack->next;
	}
	return (0);
}

int	ft_behind_median(t_stack *stack, int number)
{
	int	median;

	median = ft_stack_size(stack) / 2 + 1;
	if (ft_stack_pos(stack, number) < median)
		return (1);
	return (0);
}
