/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:05:18 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/07 12:00:01 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_display(t_stack *stack)
{
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
	int		i;

	i = 1;
	if (argc < 2 || (!argv))
	{
		ft_printf("Usage: ./push_swap [list of integers]\n");
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
	ft_stack_display(a);
	ft_stack_swap(&a, 'a');
	ft_stack_display(a);
	return (0);
}
