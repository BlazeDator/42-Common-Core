/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:08:14 by pabernar          #+#    #+#             */
/*   Updated: 2023/10/12 17:06:39 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// EOF - end of file, possibly a character
char	*get_next_line(int fd)
{
	static char	*str[42];

	ptr = malloc(BUFFER_SIZE);
	if (!ptr)
		return (0);
	read(fd, ptr, BUFFER_SIZE);
	


}
