/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:24:26 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/10 10:29:50 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin_free(char *str, char *next)
{
	char	*nstr;
	size_t	i;

	i = 0;
	nstr = malloc(ft_strlen(str) + ft_strlen(next) + 1);
	while (nstr && str[i])
	{
		nstr[i] = str[i];
		i++;
	}
	while (nstr && *next)
	{
		nstr[i] = *next;
		next++;
		i++;
	}
	free(str);
	//free(next);
	if (!nstr)
		return (0);
	nstr[i] = '\0';
	return (nstr);
}
