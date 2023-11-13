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
	ft_sort_bot(&a, &b);
	return (0);
}
