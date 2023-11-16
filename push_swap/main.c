/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:21:12 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/16 11:24:17 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	char	**strs;
	int		i;

	a = 0;
	i = 0;
	if (argc <= 1)
		return (0);
	if (argc == 2)
	{
		strs = ft_split(argv[1], ' ');
		a = ft_stack_from_argv(strs, 0);
		while (strs[i])
			free(strs[i++]);
		free(strs);
	}
	else
		a = ft_stack_from_argv(argv, 1);
	if (!a)
		return (ft_printf("Error\n"));
	if (ft_stack_sorted(a))
		return (ft_stack_free(a));
	ft_stack_display(a);
	ft_stack_free(a);
	return (0);
}
