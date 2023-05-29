#include "push_swap.h"

t_list  *ft_swap5(t_list *stack_a, t_list *stack_b)
{
    if (ft_lstsize(stack_a) == 3)
		swap3(&stack_a);
	if (ft_lstsize(stack_a) == 4)
		swap4(&stack_a, &stack_b);
	if (ft_lstsize(stack_a) == 5)
		swap5(&stack_a, &stack_b);
	return(stack_a);
}

int	*ft_arr_int(t_list *stack_a, int *j, int i)
{
	while (stack_a != NULL && i < 3)
	{
		j[i] = stack_a->content;
		stack_a = stack_a->next;
		i++;
	}
}

t_list	*swap3(t_list *stack_a)
{
	int	j[2];
	int	i;

	i = 0;
	ft_arr_int(stack_a, &j, i);
	// 1-3-2
	if (j[0] < j[1] && j[0] < j[2] && j[1] > j[2])
	{
		ra_swap(&stack_a);
		sa_swap(&stack_a);
		rra_swap(&stack_a);
	}
	// 3-2-1
	if (j[0] > j[1] && j[0] > j[2])
	{
		// 2-1
		if (j[1] > j[2])
			sa_swap(&stack_a);
		// 1-2
		else
			rra_swap(&stack_a);
		rra_swap(&stack_a);
	}
	// 2-3-1
	if (j[0] < j[1] && j[0] > j[2] && j[1] > j[2])
		rra_swap(&stack_a);
	// 2-1-3
	if (j[0] > j[1] && j[0] < j[2] && j[1] < j[2])
		sa_swap(&stack_a);
	return (stack_a);
}