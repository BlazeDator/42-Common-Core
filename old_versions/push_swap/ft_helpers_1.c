/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:34:35 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/17 10:44:52 by pabernar         ###   ########.fr       */
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

/*
	ft_node_display_one(node);
*/

int	ft_node_final(t_node *node, int max_value)
{
	while (node)
	{
		if (node->value == max_value && ft_stack_size(node->b) == 0)
		{
			ft_printf("%s", node->commands);
			return (1);
		}
		node = node->next;
	}
	return (0);
}
