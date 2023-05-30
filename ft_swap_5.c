
#include "push_swap.h"

t_list * ft_swap_5(t_list * stack_a, t_list * stack_b)
{
	if(correct_combo(stack_a) == 1)
	{
		write(1, "Correct combo!", 15);
		exit(0);
	}
	if (ft_lstsize(stack_a) == 3)
		swap3(stack_a);
	if (ft_lstsize(&stack_a) == 4)
		swap4(&stack_a, &stack_b);
	if (ft_lstsize(&stack_a) == 5)
		swap5(&stack_a, &stack_b);
	return(stack_a);
}

int	*ft_arr_int(t_list *stack_a, int *j, int i, int n)
{
	while (stack_a != NULL && i < n)
	{
		j[i] = stack_a->content;
		stack_a = stack_a->next;
		i++;
	}
	return(j);
}

void	swap3(t_list *stack_a)
{
	int	j[2];
	int	i;
	int n;
	
	n = 3;
	i = 0;
	ft_arr_int(stack_a, &j, i, n);
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
}

void	swap4(t_list *stack_a, t_list *stack_b)
{
	int	j[3];
	int i;
	int n;
	int min;
	n = 4;
	i = 0;
	ft_arr_int(stack_a, &j, i, n);
	min = min_int(j);
	while (j != NULL)
	{
		if (min == j[1])
			ra_swap(&stack_a);
		if (min == j[2])
		{
			rra_swap(stack_a);
			rra_swap(stack_a);
		}
		if (min == j[3])
			rra_swap(&stack_a);
		pb_swap(&stack_a, &stack_b);
	}
	swap3(&stack_a);
}

int	min_int(int *j)
{
	int	n;
	int i;

	i = 0;
	n = INT_MAX;
	while (j)
	{
		if (j[i] < n)
			n = j[i];
		else
			i++;
	}
	return (n);
}

int	max_int(int *j)
{
	int	n;
	int i;

	i = 0;
	n = INT_MIN;
	while (j)
	{
		if (j[i] > n)
			n = j[i];
		else
			i++;
	}
	return (n);
}