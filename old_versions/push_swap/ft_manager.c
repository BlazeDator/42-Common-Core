/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manager.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:31:40 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/18 11:55:32 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_manager(t_node *node)
{
	//ft_printf("im the manager, ill coordinate the phases and different bots\n");
	node = ft_phase_one(node);
	//ft_printf("node: %p\n", node);
	ft_node_display(node);
	//ft_printf("%s", node->commands);
	ft_node_free(node);
}
//ft_sort_bot(node);
//ft_node_free(node);
