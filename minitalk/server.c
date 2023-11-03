/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:41:18 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/03 16:03:45 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	if (argc == 0 && argv == 0)
		ft_printf("argv, argc not used");
	ft_printf("%i\n", ft_strlen("1234567890"));
	ft_printf("teste");
	return (0);
}
