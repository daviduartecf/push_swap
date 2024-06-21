/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:00:07 by daduarte          #+#    #+#             */
/*   Updated: 2024/06/19 13:17:30 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_move(char *move)
{
	ft_printf("%s\n", move);
}

t_stack	*ft_realloc(t_stack *stack, int len)
{
	if (stack != NULL)
		free(stack);
	stack = NULL;
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
	{
		ft_printf("Memory allocation failed\n");
		exit(0);
	}
	stack->stack = NULL;
	stack->len = 0;
	stack->stack = ft_calloc(len, sizeof(int));
	if (stack->stack == NULL)
	{
		ft_printf("Memory allocation failed\n");
		exit(1);
	}
	return (stack);
}

t_stack	*copy_stack(t_stack *stack, int len, int value, int flag)
{
	int		i;
	int		j;
	t_stack	*result;

	i = 0;
	j = 0;
	result = (t_stack *)malloc(sizeof(t_stack));
	if (!result)
		exit(1);
	if (len > 0)
	{
		result->stack = (int *)malloc(len * sizeof(int));
		if (!result->stack)
		{
			ft_printf("Memory allocation failed\n");
			free(result);
			exit(1);
		}
		if (flag == 1)
			result->stack[i++] = value;
		else if (flag == 0)
			j ++;
		while (i < len && j < stack->len)
			result->stack[i++] = stack->stack[j++];
	}
	result->len = len;
	return (result);
}
