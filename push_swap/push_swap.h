/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:20:45 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/14 11:08:18 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
/*
	Stack:
		struct:
*/
typedef struct s_stack
{
	int				number;
	struct s_stack	*next;
}		t_stack;
/*
		ft_stack.c:
*/
t_stack	*ft_stack_new(int num);
t_stack	*ft_stack_add_front(t_stack *stack, t_stack *new);
t_stack	*ft_stack_add_back(t_stack *stack, t_stack *new);
t_stack	*ft_stack_from_argv(char **argv);
t_stack	*ft_stack_free(t_stack *stack);
/*
		ft_stack_extras.c
*/
t_stack	*ft_stack_copy(t_stack *stack);
/*
		ft_stack_functions.c:
*/
t_stack	*ft_stack_swap(t_stack *stack);
t_stack	*ft_stack_rotate(t_stack *stack);
t_stack	*ft_stack_reverse_rotate(t_stack *stack);
void	ft_stack_push(t_stack **dest, t_stack **src);
/*
	Node:
		struct:
*/
typedef struct s_node
{
	int				value;
	int				max_value;
	char			*commands;
	t_stack			*a;
	t_stack			*b;
	struct s_node	*next;
}		t_node;
/*
		ft_node.c
*/
t_node	*ft_node_new(void);
t_node	*ft_node_add_back(t_node *node, t_node *new);
t_node	*ft_node_free(t_node *node);
/*
	Sorting:
		ft_sort_bot.c:
*/
void	ft_sort_bot(t_stack **a, t_stack **b);
/*
	Helpers:
		ft_helpers.c:
*/
int		ft_check_atoi(int num, char *str);
int		ft_stack_duplicates(t_stack *stack, int num);
int		ft_stack_sorted(t_stack *stack);
int		ft_stack_size(t_stack *stack);
/*
		ft_debug.c:
*/
void	ft_stack_display(t_stack *stack);
#endif
