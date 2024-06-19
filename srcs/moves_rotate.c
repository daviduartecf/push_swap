/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 09:48:20 by daduarte          #+#    #+#             */
/*   Updated: 2024/06/19 10:49:25 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	r(t_stack *stack)
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
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	r(stack_a);
	r(stack_b);
}

void	rrab(t_stack *stack)
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
}

void	rrab(t_stack *stack)
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
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rrab(stack_a);
	rrab(stack_b);
}
