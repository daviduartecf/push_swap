/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:58:21 by daduarte          #+#    #+#             */
/*   Updated: 2024/06/25 16:12:57 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../ft_printf/includes/ft_printf.h"
# include "../ft_printf/includes/libft.h"

typedef struct s_stack
{
	int	*stack;
	int	len;
}	t_stack;

/* PARSING INPUT FUNCTIONS */
int		ft_str_isdigit(char *str);
int		valid_arguments(int *stack, int len);
void	free_stacks(t_stack *stack_a, t_stack *stack_b);
void	error_msg(t_stack *stack_a, t_stack *stack_b, char **array, int len);
void	parse_args(t_stack *stack_a, char **argv, int len, t_stack *stack_b);
void	get_stack(t_stack *stack_a, char *argument, int *len, t_stack *stack_b);

/* MOVE HELPERS */
void	print_move(char *move);
void	free_stack_array(int **array_ptr);
t_stack	*ft_realloc(t_stack *stack, int len);
t_stack	*copy_stack(t_stack *stack, int len, int value, int flag);

/* MOVES FUNCTIONS */
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	rot_both(t_stack **stack_a, t_stack **stack_b, int *a_ind, int *b_pos);

/* SORT */
void	sort_three(t_stack *s);
int		is_sorted(t_stack *stack);
void	sort_stack(t_stack **stack_a, t_stack **stack_b);
void	sort_large(t_stack **stack_a, t_stack **stack_b);
void	move_elem(t_stack **stack_a, t_stack **stack_b, int a_ind, int b_pos);
void	insert_elem(t_stack **stack_a, t_stack **stack_b, int b_ind, int a_pos);

/* FIND CHEAPEST */
int		get_max_index(t_stack *stack);
int		get_min_index(t_stack *stack);
int		is_min(t_stack *stack, int value);
int		is_max(t_stack *stack, int value);
int		position_in_stackb(t_stack *stack, int value);
int		position_in_stacka(t_stack *stack, int value);
int		cheapest(t_stack *stack_a, t_stack *stack_b, int *a_index, int *b_pos);
int		cheapest_a(t_stack *stack_a, t_stack *stack_b, int *b_ind, int *a_pos);
int		common_moves(t_stack *stack_a, t_stack *stack_b, int a_ind, int b_pos);
int		total_moves(t_stack *stack_a, t_stack *stack_b, int a_index, int b_pos);

#endif
