/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:21:12 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/17 10:35:45 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**ft_word_array_free(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	char	**strs;

	a = 0;
	if (argc <= 1)
		return (0);
	if (argc == 2)
	{
		strs = ft_split(argv[1], ' ');
		a = ft_stack_from_argv(strs, 0);
		strs = ft_word_array_free(strs);
	}
	else
		a = ft_stack_from_argv(argv, 1);
	if (!a)
		return (ft_printf("Error\n"));
	if (ft_stack_sorted(a))
	{
		a = ft_stack_free(a);
		return (0);
	}
	ft_manager(ft_stack_to_node(a));
	return (0);
}
