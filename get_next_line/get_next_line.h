/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:08:51 by pabernar          #+#    #+#             */
/*   Updated: 2023/10/17 12:22:12 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_strlen(const char *s);

char	*get_next_line(int fd);
char	*ft_check_str(char *str, int charead);
char	*ft_buffer_to_str(char	*src);

int		ft_str_has_newline(char *str);
int		ft_buffer_is_empty(char *buffer);

#endif
