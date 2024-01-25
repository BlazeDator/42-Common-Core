/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 09:37:04 by pabernar          #+#    #+#             */
/*   Updated: 2024/01/25 10:53:31 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	ft_check_open_quotes(char *line);

void	ft_parser(char *line)
{
	if (!ft_check_open_quotes(line))
		return ;
}

int	ft_check_open_quotes(char *line)
{
	char	quote;
	int		state;

	state = 0;
	while (*line)
	{
		if (!state && (*line == '\'' || *line == '\"'))
		{
			state = 1;
			quote = *line;
		}
		else if (state && *line == quote)
			state = 0;
		line++;
	}
	if (state && write(2, "Error: Open quotes\n", 19))
		return (0);
	return (1);
}
