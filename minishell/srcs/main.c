/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:48:43 by pabernar          #+#    #+#             */
/*   Updated: 2024/01/22 12:43:58 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	main(void)
{
	char	dir[256];
	char	*str;

	getcwd(dir, 256);
	while (1)
		str = readline(dir);
	ft_printf("Hello %s\n", str);
	free(str);
	return (0);
}
