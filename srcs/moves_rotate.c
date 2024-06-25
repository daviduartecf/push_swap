/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 09:48:20 by daduarte          #+#    #+#             */
/*   Updated: 2024/06/25 10:00:27 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack *stack)
{
	int	i;
	int	temp;

	if (stack->len <= 1)
		return ;
	i = 0;
	temp = stack->stack[0];
	while (i < stack->len - 1)
	{
		stack->stack[i] = stack->stack[i + 1];
		i ++;
	}
	stack->stack[stack->len - 1] = temp;
	print_move("ra");
}

void	rb(t_stack *stack)
{
	int	i;
	int	temp;

	if (stack->len <= 1)
		return ;
	i = 0;
	temp = stack->stack[0];
	while (i < stack->len - 1)
	{
		stack->stack[i] = stack->stack[i + 1];
		i ++;
	}
	stack->stack[stack->len - 1] = temp;
	print_move("rb");
}

void	rra(t_stack *stack)
{
	int	i;
	int	temp;

	if (stack->len <= 1)
		return ;
	i = stack->len - 1;
	temp = stack->stack[stack->len - 1];
	while (i > 0)
	{
		stack->stack[i] = stack->stack[i - 1];
		i --;
	}
	stack->stack[0] = temp;
	print_move("rra");
}

void	rrb(t_stack *stack)
{
	int	i;
	int	temp;

	if (stack->len <= 1)
		return ;
	i = stack->len - 1;
	temp = stack->stack[stack->len - 1];
	while (i > 0)
	{
		stack->stack[i] = stack->stack[i - 1];
		i --;
	}
	stack->stack[0] = temp;
	print_move("rrb");
}
