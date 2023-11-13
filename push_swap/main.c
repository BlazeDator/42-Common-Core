/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:21:12 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/13 15:19:32 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = 0;
	b = 0;
	if (argc <= 2)
		return (0);
	a = ft_stack_from_argv(argv);
	if (!a)
	{
		ft_printf("Error\n");
		return (0);
	}
	if (ft_stack_sorted(a))
	{
		ft_stack_free(a);
		return (0);
	}
	// TODO: Write tests for all the functions, theyre not working properly
	// TODO: valgrind ./push_swap 3 2 1 is buggy with the following test
	// ft_sort_bot(&a, &b);
	ft_stack_display(a);
	ft_stack_display(b);

	ft_stack_push(&b, &a);
	ft_stack_push(&b, &a);
	ft_stack_push(&b, &a);
	
	ft_printf("\n");	
	ft_stack_display(a);
	ft_stack_display(b);

	ft_stack_rotate(b);
	ft_stack_rotate(b);
	ft_stack_rotate(b);

	ft_printf("\n");	
	ft_stack_display(a);
	ft_stack_display(b);

	ft_stack_push(&a, &b);
	ft_stack_push(&a, &b);
	ft_stack_push(&a, &b);
	
	ft_printf("\n");	
	ft_stack_display(a);
	ft_stack_display(b);
	if (a)
		ft_stack_free(a);
	if (b)
		ft_stack_free(b);
	return (0);
}
