/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manager.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:31:40 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/18 09:13:52 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_manager(t_node *node)
{
	ft_printf("im the manager, ill coordinate the phases and different bots\n");
	//node = ft_phase_one(node);	

	ft_sort_bot(node);
}
/*ft_node_free(node);*/
/*
t_node	*ft_phase_one(t_node *node)
{
	if (ft_stack_size(node->a > 3))
	{
		ft_stack_push(node->b, node->a);
		ft_stack_push(node->b, node->a);
		//TODO: Phase 1 sort bot
	}
}*/
