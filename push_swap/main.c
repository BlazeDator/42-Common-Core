/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:05:18 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/09 15:08:05 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_display(t_stack *stack, char name)
{
	if (name)
		ft_printf("stack %c: ", name);
	while (stack)
	{
		ft_printf("%i -> ", stack->num);
		stack = stack->next;
	}
	ft_printf("\n");
}

int	ft_stack_duplicate(t_stack *stack, int num)
{
	while (stack)
	{
		if (stack->num == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack *b;
	int		i;
	int		num;
	char	*commands;

	i = 1;
	a = 0;
	b = 0;
	if (argc < 2 || (!argv))
	{
		return (0);
	}
	// Create Stack from argv
	a = ft_stack_new(ft_atoi(argv[i]));
	i++;
	while (argv[i])
	{
		num = ft_atoi(argv[i]);
		if (ft_stack_duplicate(a, num) || (num == 0 && argv[i][0] != '0'))
			return (ft_printf("Error\n"));
		ft_stack_add_back(&a, ft_stack_new(ft_atoi(argv[i])));
		i++;
	}
	// Test new stack functions
	ft_printf("Stacks Initial State:\n");
	ft_stack_display(a, 'a');
	ft_stack_display(b, 'b');
	commands = ft_stack_sorter(&a, &b);
	ft_printf("%s", commands);
	//free(commands);
	//ft_stack_clear(a);
	//ft_stack_clear(b);
	return (0);
}
/*
	ft_stack_push(&b, &a, 'b');
	ft_stack_display(a, 'a');
	ft_stack_display(b, 'b');
	
	ft_stack_push(&a, &b, 'a');
	ft_stack_display(a, 'a');
	ft_stack_display(b, 'b');

	ft_stack_swap(&a, 'a');
	ft_stack_display(a, 'a');
	ft_stack_display(b, 'b');
	
	ft_stack_rotate(&a, 'a');
	ft_stack_display(a, 'a');

	ft_stack_reverse_rotate(&a, 'a');
	ft_stack_display(a, 'a');
	return (0);
*/
