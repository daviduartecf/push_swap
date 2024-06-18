#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
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
void	get_stack_from_argument(t_stack *stack_a, char *argument, int *len, t_stack *stack_b);

/* MOVE HELPERS */
t_stack	*copy_stack(t_stack **stack, int len, int value, int flag);
t_stack	*ft_realloc(t_stack *stack, int len);

/* MOVES FUNCTIONS */
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);

#endif
