/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:21:12 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/13 11:48:21 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = 0;
	b = 0;
	if (argc < 2)
		return (0);
	a = ft_stack_from_argv(argv);
	if (!a)
	{
		ft_printf("Error\n");
		return (0);
	}
	ft_stack_display(a);
	ft_stack_free(a);
	return (0);
}
