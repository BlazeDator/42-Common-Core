/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:20:26 by pabernar          #+#    #+#             */
/*   Updated: 2024/01/15 11:50:14 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_itoalen(int n);

int	ft_atoi(const char *str)
{
	int	sum;
	int	i;
	int	signs;

	i = 0;
	sum = 0;
	signs = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signs++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		sum = sum * 10 + (str[i] - '0');
		i++;
	}
	if (signs)
		sum *= -1;
	return (sum);
}

size_t	ft_strlen(const char *s)
{
	size_t			count;

	count = 0;
	while (*s)
	{
		count++;
		s++;
	}
	return (count);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	i = 0;
	ptr1 = (unsigned char *) s1;
	ptr2 = (unsigned char *) s2;
	while (i < n)
	{
		if (ptr1[i] != ptr2[i] || !ptr1[i] || !ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (0);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_itoalen(n);
	str = malloc(len);
	if (!str)
		return (0);
	if (n < 0)
		str[0] = '-';
	else if (n == 0)
		str[0] = '0';
	str[len - 1] = '\0';
	while (n != 0)
	{
		if (n < 0)
			str[len - 2] = (n % 10 * -1) + 48;
		else
			str[len - 2] = (n % 10) + 48;
		n /= 10;
		len--;
	}
	return (str);
}

static int	ft_itoalen(int n)
{
	int	count;

	count = 0;
	if (n >= 0)
		count++;
	else
		count += 2;
	if (n == 0)
		return (count + 1);
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}
