/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_bot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:12:46 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/15 13:18:00 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_bot(t_stack **a)
{
	t_node	*node;
	t_node	*new;
	int		max_value;

	max_value = (ft_stack_size(*a) - 1) * 2;
	node = ft_node_new();
	node->a = ft_stack_copy(*a);
	*a = ft_stack_free(*a);
	new = 0;
	while (!ft_node_final(node, max_value))
	{
		ft_generate_nodes(node, &new);
		ft_calculate_value(new);
		node = ft_node_free(node);
		node = ft_value(new);
		new = ft_node_free(new);
	}
	node = ft_node_free(node);
}
/*
	valgrind ./push_swap -1 -2 -3 0 5 -9
	Current : 13 629
	History:
	29 000
	5 092 822 allocs

	valgrind ./push_swap -1 -2 -3 0 5 -9 100 -500
	Current: 45 027

	./push_swap -1 -2 -3 0 5 -9 100 -500 1000 5000 2000 -950 900 8 10
	Current: 14 996 572
	it orders it but with valgrind takes too long

	./push_swap -1 -2 -3 0 5 -9 100 -500 1000 5000 2000 -950 900 8 10 15 52 23

*/

void	ft_generate_nodes(t_node *node, t_node **new)
{
	int	i;

	i = 0;
	while (node)
	{
		while (i < 11)
		{
			*new = ft_node_add_front(*new, ft_node_new());
			(*new)->a = ft_stack_copy(node->a);
			(*new)->b = ft_stack_copy(node->b);
			(*new)->commands = ft_strjoin_f((*new)->commands, node->commands);
			if (i >= 0 && i <= 2)
				*new = ft_generate_a(*new, i);
			else if (i >= 3 && i <= 5)
				*new = ft_generate_b(*new, i);
			else if (i >= 6 && i <= 8)
				*new = ft_generate_a_and_b(*new, i);
			else if (i >= 9 && i <= 10)
				*new = ft_generate_push(*new, i);
			i++;
		}
		i = 0;
		node = node->next;
	}
}

t_node	*ft_value(t_node *node)
{
	t_node	*new;
	int		value;

	value = 0;
	new = 0;
	value = ft_max_value(node);
	while (node)
	{
		if (node->value >= (value - 2) && ft_check_duplicates(node, new))
		{
			new = ft_node_add_front(new, ft_node_new());
			new->a = ft_stack_copy(node->a);
			new->b = ft_stack_copy(node->b);
			new->commands = ft_strjoin_f(new->commands, node->commands);
			new->value = node->value;
		}
		node = node->next;
	}
	return (new);
}

void	ft_calculate_value(t_node *node)
{
	while (node)
	{
		node->value = ft_stack_value(node->a, node->b);
		node = node->next;
	}
}

char	*ft_strjoin_f(char *commands, char *nstr)
{
	char	*temp;

	temp = ft_strjoin(commands, nstr);
	free(commands);
	return (temp);
}
