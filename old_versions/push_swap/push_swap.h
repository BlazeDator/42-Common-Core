/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:20:45 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/17 09:03:20 by pabernar         ###   ########.fr       */
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
t_stack	*ft_stack_from_argv(char **argv, int mode);
t_stack	*ft_stack_free(t_stack *stack);
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
	int				last_c;
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
t_node	*ft_node_add_front(t_node *node, t_node *new);
t_node	*ft_node_free(t_node *node);
/*
	Sorting:
		ft_sort_bot.c:
*/
void	ft_sort_bot(t_stack **a);
void	ft_generate_nodes(t_node *node, t_node **new);
t_node	*ft_value(t_node *node);
void	ft_calculate_value(t_node *node);
char	*ft_strjoin_f(char *commands, char *nstr);
/*
	Generation:
		ft_generators.c
*/
t_node	*ft_generate_a(t_node *node, int i);
t_node	*ft_generate_b(t_node *node, int i);
t_node	*ft_generate_a_and_b(t_node *node, int i);
t_node	*ft_generate_push(t_node *node, int i);
/*
	Helpers:
		ft_helpers_1.c:
*/
int		ft_check_atoi(int num, char *str);
int		ft_stack_duplicates(t_stack *stack, int num);
int		ft_stack_sorted(t_stack *stack);
int		ft_stack_size(t_stack *stack);
int		ft_node_final(t_node *node, int max_value);
/*
		ft_helpers_2.c
*/
t_stack	*ft_stack_copy(t_stack *stack);
int		ft_stack_value(t_stack *a, t_stack *b);
int		ft_max_value(t_node *traveler);
int		ft_check_duplicates(t_node *node, t_node *new);
int		ft_stack_identical(t_stack *stack, t_stack *copies);
/*
		ft_helpers_3.c
*/
int		ft_check_useless(t_node *node, int i);
/*
		ft_debug.c:
*/
void	ft_stack_display(t_stack *stack);
void	ft_node_display(t_node *traveler);
void	ft_node_display_one(t_node *traveler);
#endif
