/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:48:43 by pabernar          #+#    #+#             */
/*   Updated: 2024/01/22 14:09:28 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	main(void)
{
	char	dir[256];
	char	*str;
	char	**array;

	getcwd(dir, 256);
	array = ft_split(dir, '/');
	while (*(array + 1))
		array++;
	*array = ft_strjoin("MINISHELL [/", *array);
	*array = ft_strjoin(*array, "]>");
	while (1)
		str = readline(*array);
	free(str);
	return (0);
}
