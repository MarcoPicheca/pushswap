/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_move_c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:14:16 by mapichec          #+#    #+#             */
/*   Updated: 2024/02/20 15:51:05 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	from_b_to_a(int a, int b, t_list **stack_a, t_list **stack_b)
{
	while (a != 0 || b != 0)
	{
		if (b > 0 && a > 0)
		{
			rr(stack_a, stack_b);
			b--;
			a--;
		}
		else if (b < 0 && a < 0)
		{
			rrr(stack_a, stack_b);
			b++;
			a++;
		}
		else if (b < 0 && a == 0)
		{
			rrb(stack_b, 0);
			b++;
		}
		else if (a < 0 && b == 0)
		{
			rra(stack_a, 0);
			a++;
		}
		else if (b > 0 && a == 0)
		{
			rb(stack_b, 0);
			b--;
		}
		else if (a > 0 && b == 0)
		{
			ra(stack_a, 0);
			a--;			
		}
		else if (a < 0 && b > 0)
		{
			rra(stack_a, 0);
			rb(stack_b, 0);
			a++;
			b--;
		}
		else if (a > 0 && b < 0)
		{
			rrb(stack_b, 0);
			ra(stack_a, 0);
			a--;
			b++;
		}
		else if (a == 0 && b == 0)
			break;
	}
	pa(stack_a, stack_b);
}

// TODO: TOGLIERE
void arr_print_c(int *move_c, int size)
{
	int i = 0;
	while (i < size){
		printf("%d = MOVE_C[%d]\n", i , move_c[i]);
		i++;
	}
}

void arr_print_a_b(int *move_a, int *move_b, int size)
{
	int i = 0;
	while (i < size){
		printf("%d = move_a[%d] = move_a[%d]\n", i , move_a[i], move_b[i]);
		i++;
	}
}

void	actual_moves(int *move_a, int *move_b, int *move_c, t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	g;
	int	j;

	g = INT_MAX;	
	i = 0;
	j = 0;
	while (i < ft_lstsize((*stack_b)))
	{
		if (move_c[i] < g)
		{
			g = move_c[i];
			j = i;
		}
		i++;
	}
	arr_print_a_b(move_a, move_b, ft_lstsize((*stack_b)));
	arr_print_c(move_c, ft_lstsize((*stack_b)));
	from_b_to_a(move_a[j], move_b[j], stack_a, stack_b);
}

int	ft_move_c(int *move_a, int *move_b, int *move_c, t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = 0;
	while (i < ft_lstsize((*stack_b)))
	{
		if (move_b[i] < 0 && move_a[i] >= 0)
			move_c[i] = (move_b[i] * -1) + move_a[i];
		else if (move_b[i] >= 0 && move_a[i] < 0)
			move_c[i] = (move_a[i] * -1) + move_b[i];
		else if (move_b[i] < 0 && move_a[i] < 0 && move_b[i] < move_a[i])
			move_c[i] = (move_b[i] * -1) - (move_a[i] * -1);
		else if (move_b[i] < 0 && move_a[i] < 0 && move_b[i] >= move_a[i])
			move_c[i] = (move_a[i] * -1) - (move_b[i] * -1);
		else if (move_b[i] >= 0 && move_a[i] >= 0 && move_b[i] >= move_a[i])
			move_c[i] = move_b[i] - move_a[i];
		else if (move_b[i] >= 0 && move_a[i] >= 0 && move_b[i] < move_a[i])
			move_c[i] = move_a[i] - move_b[i];
		i++;
	}
	actual_moves(move_a, move_b, move_c, stack_a, stack_b);
	return (1);
}
