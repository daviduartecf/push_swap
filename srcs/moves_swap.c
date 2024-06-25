/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:38:38 by daduarte          #+#    #+#             */
/*   Updated: 2024/06/25 10:44:43 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack *stack_a)
{
	int	temp;

	if (stack_a->len < 2)
		return ;
	temp = stack_a->stack[0];
	stack_a->stack[0] = stack_a->stack[1];
	stack_a->stack[1] = temp;
	print_move("sa");
}

void	sb(t_stack *stack_b)
{
	int	temp;

	if (stack_b->len < 2)
		return ;
	temp = stack_b->stack[0];
	stack_b->stack[0] = stack_b->stack[1];
	stack_b->stack[1] = temp;
	print_move("sb");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	int	temp;

	if (stack_a->len >= 2)
	{
		temp = stack_a->stack[0];
		stack_a->stack[0] = stack_a->stack[1];
		stack_a->stack[1] = temp;
	}
	if (stack_b->len < 2)
	{
		temp = stack_b->stack[0];
		stack_b->stack[0] = stack_b->stack[1];
		stack_b->stack[1] = temp;
	}
	print_move("ss");
}
