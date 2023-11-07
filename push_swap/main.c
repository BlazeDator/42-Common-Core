/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:05:18 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/07 12:58:13 by pabernar         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack *b;
	int		i;

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
		ft_stack_add_back(&a, ft_stack_new(ft_atoi(argv[i])));
		i++;
	}
	// Test new stack functions
	ft_stack_display(a, 'a');
	ft_stack_display(b, 'b');

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

	return (0);
}
