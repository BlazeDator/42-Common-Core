/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:20:45 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/10 11:52:39 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}		t_stack;

typedef struct s_queue_node
{
	int				base_improvement;
	int				max_improvement;
	char	*commands;
	t_stack	*a;
	t_stack	*b;
	struct s_queue_node	*next;
}		t_queue_node;

char	*ft_strjoin_free(char *str, char *next);

t_stack	*ft_stack_new(int num);
t_stack *ft_stack_copy(t_stack *stack);

void	ft_stack_add_front(t_stack **stack, t_stack *new);
void	ft_stack_add_back(t_stack **stack, t_stack *new);

char	*ft_stack_swap(t_stack **stack, char *name);
char	*ft_stack_push(t_stack **dest, t_stack **src, char *name);
char	*ft_stack_rotate(t_stack **stack, char *name);
char	*ft_stack_reverse_rotate(t_stack **stack, char *name);

void	ft_stack_display(t_stack *stack, char name);
void	ft_stack_clear(t_stack *stack);

char	*ft_stack_sorter(t_stack **a, t_stack **b);
char	*ft_check_sorted(t_queue_node *node);

int		ft_stack_size(t_stack *stack);
int		ft_stack_calc_improvement(t_stack *a, t_stack *b);

t_queue_node *ft_queue_node_new(t_stack *a, t_stack *b, char *commands);

void	ft_queue_node_add_back(t_queue_node **node, t_queue_node *new);
void	ft_queue_node_add_front(t_queue_node **node, t_queue_node *new);
void	ft_queue_node_delone(t_queue_node *node);
void	ft_queue_node_clear(t_queue_node **node);
void	ft_update_improvement(t_queue_node *node);
void	ft_clean_improvement(t_queue_node **queue);

void	ft_display_queue(t_queue_node *queue);
void	ft_queue_size(t_queue_node *queue);
#endif
