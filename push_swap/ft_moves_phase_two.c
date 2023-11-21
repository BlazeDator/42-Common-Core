/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_phase_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:53:04 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/21 11:15:51 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_phase_two(t_stack **a, char **commands)
{
	if (ft_stack_sorted(*a))
		return ;
	if (ft_stack_size(*a) == 2)
	{
		*a = ft_stack_swap(*a);
		*commands = ft_strjoin_f(*commands, "sa\n");
		return ;
	}
	if ((*a)->next->number < (*a)->number)
	{
		*a = ft_stack_swap(*a);
		*commands = ft_strjoin_f(*commands, "sa\n");
	}
	if ((*a)->next->next->number > (*a)->number)
	{
		*a = ft_stack_reverse_rotate(*a);
		*commands = ft_strjoin_f(*commands, "rra\n");
		*a = ft_stack_swap(*a);
		*commands = ft_strjoin_f(*commands, "sa\n");
	}
	if ((*a)->next->next->number < (*a)->number)
	{
		*a = ft_stack_reverse_rotate(*a);
		*commands = ft_strjoin_f(*commands, "rra\n");
	}
}
