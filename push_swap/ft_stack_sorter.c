/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_sorter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:33:10 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/09 13:10:05 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_queue_node	*ft_generate_nodes(t_queue_node *queue, t_queue_node **new_queue)
{
	int	i;

	i = 0;
	while (i < 11)
	{
		ft_queue_node_add_front(new_queue, 
			ft_queue_node_new(queue->a, queue->b, queue->commands));
		i++;
	}
	return (new_queue[0]);
}

void	ft_generate_commands(char *(*commands[11]))
{
	commands[0][0] = "sa";
	commands[0][1] = "sb";
	commands[0][2] = "ss";
	commands[0][3] = "ra";
	commands[0][4] = "rb";
	commands[0][5] = "rr";
	commands[0][6] = "rra";
	commands[0][7] = "rrb";
	commands[0][8] = "rrr";
	commands[0][9] = "pa";
	commands[0][10] = "pb";
}

void	ft_generate_functions(char *(*functions[9]) (t_stack **stack, char *name))
{
	functions[0] = ft_stack_swap; 
	functions[1] = ft_stack_swap;
	functions[2] = ft_stack_swap;
	functions[3] = ft_stack_rotate;
	functions[4] = ft_stack_rotate;
	functions[5] = ft_stack_rotate;
	functions[6] = ft_stack_reverse_rotate;
	functions[7] = ft_stack_reverse_rotate;
	functions[8] = ft_stack_reverse_rotate;
}

void	ft_generate_possibilities(t_queue_node *queue, t_queue_node **new_queue)
{
	t_queue_node	*start;
	char	*(*functions[9]) (t_stack **stack, char *name);
	char	*(*commands[11]);
	int	i;

	i = 0;
	new_queue[0] = ft_generate_nodes(queue, new_queue);
	ft_generate_commands(commands);
	ft_generate_functions(functions);
	start = new_queue[0];
	while (i < 11)
	{
		if (i == 0 || i == 3 || i == 6)
			new_queue[0]->commands = 
			ft_strjoin(queue->commands, 
			functions[i](&new_queue[0]->a, commands[0][i]));
		else if (i == 1 || i == 4 || i == 7)
			new_queue[0]->commands =
			ft_strjoin(queue->commands, 
			functions[i](&new_queue[0]->b, commands[0][i]));
		else if (i == 9)
			new_queue[0]->commands =
			ft_strjoin(queue->commands, 
			ft_stack_push(&new_queue[0]->a, &new_queue[0]->b, commands[0][i]));
		else if (i == 10)
			new_queue[0]->commands =
			ft_strjoin(queue->commands,
			ft_stack_push(&new_queue[0]->b, &new_queue[0]->a, commands[0][i]));
		else
		{
			new_queue[0]->commands =
			ft_strjoin(queue->commands, 
			functions[i](&new_queue[0]->a, commands[0][i]));
			functions[i](&new_queue[0]->b, commands[0][i]);
		}
		new_queue[0] = new_queue[0]->next;
		i++;
	}
	new_queue[0] = start;
}

char	*ft_stack_sorter(t_stack **a, t_stack **b)
{
	t_queue_node *queue;
	t_queue_node *new_queue;
	t_queue_node *start;
	char	*commands;

	commands = 0;	
	queue = ft_queue_node_new(a[0], b[0], "");
	while (!commands)
	{
		start = queue;
		commands = ft_check_sorted(queue);
		if (commands)
			break ;
		while (queue)
		{
			ft_generate_possibilities(queue, &new_queue); 
			queue = queue->next;
		}
		queue = start;
		ft_queue_node_clear(queue);
		ft_clean_improvement(&new_queue);
		queue = new_queue;
	}
	ft_queue_node_clear(start);
	return (commands);
}
