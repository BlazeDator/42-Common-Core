/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:20:45 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/21 14:39:10 by pabernar         ###   ########.fr       */
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
	int				target;
	int				push_cost;
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
		ft_stack_helpers.c:
*/
int		ft_stack_duplicates(t_stack *stack, int num);
int		ft_stack_sorted(t_stack *stack);
int		ft_stack_size(t_stack *stack);
/*
		ft_algorithm.c
*/
void	ft_algorithm(t_stack *a);
/*
		ft_targets.c
*/
void	ft_calc_targets_one(t_stack *a, t_stack *b);
void	ft_calc_targets_three(t_stack *a, t_stack *b);
/*
		ft_push_cost_one.c
*/
void	ft_calc_push_cost_one(t_stack *a, t_stack *b);
int		ft_lowest_cost(t_stack *stack);
/*
		ft_moves_phase_one.c
*/
void	ft_phase_one(t_stack **a, t_stack **b);
void	ft_move_cheapest(t_stack **a, t_stack **b, int cheap, int target);
void	ft_rot_phase_one(t_stack **a, t_stack **b, int cheap, int target);
void	ft_rev_phase_one(t_stack **a, t_stack **b, int cheap, int target);
/*
		ft_moves_phase_two.c
*/
void	ft_phase_two(t_stack **a);
/*
		ft_moves_phase_three.c
*/
void	ft_phase_three(t_stack **a, t_stack **b);
void	ft_move_cheap_b(t_stack **a, t_stack **b, int cheap, int target);
void	ft_rot_phase_b(t_stack **a, t_stack **b, int cheap, int target);
void	ft_rev_phase_b(t_stack **a, t_stack **b, int cheap, int target);
/*
		ft_helpers.c:
*/
int		ft_check_atoi(int num, char *str);
int		ft_stack_pos(t_stack *stack, int num);
int		ft_stack_target(t_stack *stack, int num);
int		ft_behind_median(t_stack *stack, int number);
/*
		ft_math.c
*/
int		ft_min(int n1, int n2);
/*
		ft_debug.c:
*/
void	ft_stack_display(t_stack *stack);
void	ft_targets_display(t_stack *stack);
#endif
