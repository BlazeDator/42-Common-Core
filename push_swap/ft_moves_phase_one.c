/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_phase_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:19:33 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/21 09:25:09 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rot_phase_one(t_stack **a, t_stack **b, int cheap, char **commands)
{
	if (ft_behind_median(*a, cheap)
		&& ft_behind_median(*b, ft_stack_target(*a, cheap))
		&& ft_stack_pos(*a, cheap) > 0
		&& ft_stack_pos(*b, ft_stack_target(*a, cheap)) > 0)
	{
		*a = ft_stack_rotate(*a);
		*b = ft_stack_rotate(*b);
		*commands = ft_strjoin_f(*commands, "rr\n");
	}
	else if (ft_behind_median(*a, cheap) && ft_stack_pos(*a, cheap) > 0)
	{
		*a = ft_stack_rotate(*a);
		*commands = ft_strjoin_f(*commands, "ra\n");
	}
	else if (ft_behind_median(*b, ft_stack_target(*a, cheap))
		&& ft_stack_pos(*b, ft_stack_target(*a, cheap)) > 0)
	{
		*b = ft_stack_rotate(*b);
		*commands = ft_strjoin_f(*commands, "rb\n");
	}
}
