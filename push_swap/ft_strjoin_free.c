/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:24:26 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/10 12:21:49 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strlen_safe(char	*str)
{
	int	count;

	count = 0;
	if(!str)
		return (0);
	while (str[count])
		count++;
	return (count);
}

char	*ft_strjoin_free(char *str, char *next)
{
	char	*nstr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	nstr = malloc(ft_strlen_safe(str) + ft_strlen_safe(next) + 1);
	while (nstr && str && str[i])
	{
		nstr[i] = str[i];
		i++;
	}
	while (nstr && next && next[j])
	{
		nstr[i] = next[j];
		j++;
		i++;
	}
	//if (str && str[0])
	//	free(str);
	//free(next);
	if (!nstr)
		return (0);
	nstr[i] = '\0';
	return (nstr);
}
