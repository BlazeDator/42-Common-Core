/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_sorter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:33:10 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/09 15:22:21 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// MAX IMPROVEMENT VARIA COM A STACK A E B MUDA O CODIGO DO IMPROVEMENT
// ft_printf("\n");

void	ft_generate_nodes(t_queue_node *queue, t_queue_node **new_queue)
{
	int	i;

	i = 0;
	while (i < 11)
	{
		ft_queue_node_add_front(new_queue, 
			ft_queue_node_new(queue->a, queue->b, queue->commands));
		i++;
	}
	ft_printf("Generating Nodes: \n");
	ft_display_queue(new_queue[0]);
}

char	**ft_generate_commands()
{
	char	**commands;

	commands = malloc(11 * sizeof(char *));
	commands[0] = ft_strdup("sa\n");
	commands[1] = ft_strdup("sb\n");
	commands[2] = ft_strdup("ss\n");
	commands[3] = ft_strdup("ra\n");
	commands[4] = ft_strdup("rb\n");
	commands[5] = ft_strdup("rr\n");
	commands[6] = ft_strdup("rra\n");
	commands[7] = ft_strdup("rrb\n");
	commands[8] = ft_strdup("rrr\n");
	commands[9] = ft_strdup("pa\n");
	commands[10] = ft_strdup("pb\n");
	return (commands);
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
	char	**commands;// TODO:Dont forget to free
	int	i;


	i = 0;
	ft_printf("Generating Possibilities\n");
	ft_generate_nodes(queue, new_queue);
	ft_printf("Generating Commands\n");
	commands = ft_generate_commands();
	ft_printf("Generating Functions\n");
	ft_generate_functions(functions);
	start = new_queue[0];
	while (i < 11)
	{
		if (i == 0 || i == 3 || i == 6)
			new_queue[0]->commands = 
			ft_strjoin(queue->commands, 
			functions[i](&new_queue[0]->a, commands[i]));
		else if (i == 1 || i == 4 || i == 7)
			new_queue[0]->commands =
			ft_strjoin(queue->commands, 
			functions[i](&new_queue[0]->b, commands[i]));
		else if (i == 9)
			new_queue[0]->commands =
			ft_strjoin(queue->commands, 
			ft_stack_push(&new_queue[0]->a, &new_queue[0]->b, commands[i]));
		else if (i == 10)
			new_queue[0]->commands =
			ft_strjoin(queue->commands,
			ft_stack_push(&new_queue[0]->b, &new_queue[0]->a, commands[i]));
		else
		{
			new_queue[0]->commands =
			ft_strjoin(queue->commands, 
			functions[i](&new_queue[0]->a, commands[i]));
			functions[i](&new_queue[0]->b, commands[i]);
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
	new_queue = 0;
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
	ft_printf("Sorted\n");
	ft_queue_node_clear(start);
	return (commands);
}
