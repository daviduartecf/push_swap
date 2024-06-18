/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 09:29:25 by daduarte          #+#    #+#             */
/*   Updated: 2024/06/18 17:55:13 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	len = 0;

	i = 0;
	if (stack_a->len > stack_b->len)
		len = stack_a->len;
	else
		len =stack_b->len;
	while (i < len)
	{
		if (i < stack_a->len)
			ft_printf("%d  ", stack_a->stack[i]);
		else
			ft_printf("   ");
		if (i < stack_b->len)
			ft_printf("%d", stack_b->stack[i]);
		else
			ft_printf("   ");
		ft_printf("\n");
		i ++;
	}
	ft_printf("-- --\n");
	ft_printf("A   B\n");
	ft_printf("A: %d   B: %d\n", stack_a->len, stack_b->len);
}

t_stack	*stack_init()
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
	{
		ft_printf("Memory allocation failed\n");
		exit(0);
	}
	stack->stack = NULL;
	stack->len = 0;
	return (stack);
}

void	free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->stack);
	free(stack_a);
	free(stack_b->stack);
	free(stack_b);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = stack_init();
	stack_b = stack_init();
	if (argc == 1)
		exit(0);
	if (argc == 2)
	{
		get_stack_from_argument(stack_a, argv[1], &stack_a->len, stack_b);
	}
	else
	{
		ft_printf("Let's see!");
	}
	print_stacks(stack_a, stack_b);
	//sa(stack_a);
	//sb(stack_b);
	pb(&stack_a, &stack_b);
	ft_printf("\n");
	print_stacks(stack_a, stack_b);
	pb(&stack_a, &stack_b);
	sb(stack_b);
	ft_printf("\n");
	print_stacks(stack_a, stack_b);
	free_stacks(stack_a, stack_b);
	return (0);
}
