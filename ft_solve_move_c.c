/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_move_c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:14:16 by mapichec          #+#    #+#             */
/*   Updated: 2024/02/19 16:33:09 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	from_b_to_a(int **moves, int j, int c, t_list **stack_a, t_list **stack_b)
{
	int	a;
	int	b;

	b = moves[0][j];
	a = moves[1][j];
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
		c--;
	}
	pa(stack_a, stack_b);
}

void	actual_moves(int *move_c, t_list **stack_a, t_list **stack_b, int **moves)
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
	from_b_to_a(moves, j, move_c[j], stack_a, stack_b);
}

int	ft_move_c(int **moves, t_list **stack_a, t_list **stack_b)
{
	int	*move_c;
	t_list *node;
	int	i;

	i = 0;
	node = (*stack_b);
	if (ft_lstsize((*stack_b)) == 0)
		return (1);
	move_c = (int *)malloc(sizeof(int) * ft_lstsize((*stack_b)));
	if (!move_c)
		return (0);
	while (i < ft_lstsize((*stack_b)))
	{
		if (moves[0][i] < 0 && moves[1][i] >= 0)
			move_c[i] = (moves[0][i] * -1) + moves[1][i];
		else if (moves[0][i] >= 0 && moves[1][i] < 0)
			move_c[i] = (moves[1][i] * -1) + moves[0][i];
		else if (moves[0][i] < 0 && moves[1][i] < 0 && moves[0][i] < moves[1][i])
			move_c[i] = (moves[0][i] * -1) - (moves[1][i] * -1);
		else if (moves[0][i] < 0 && moves[1][i] < 0 && moves[0][i] >= moves[1][i])
			move_c[i] = (moves[1][i] * -1) - (moves[0][i] * -1);
		else if (moves[0][i] >= 0 && moves[1][i] >= 0 && moves[0][i] >= moves[1][i])
			move_c[i] = moves[0][i] - moves[1][i];
		else if (moves[0][i] >= 0 && moves[1][i] >= 0 && moves[0][i] < moves[1][i])
			move_c[i] = moves[1][i] - moves[0][i];
		// ft_printf("move_a[%d]\tmove_b [%d]\n", moves[0][i], moves[1][i]);
		// ft_printf("move_c[%d] = [%d] = node [%d]\n", move_c[i], i, node->content);
		node = node->next;
		i++;
	}
	actual_moves(move_c, stack_a, stack_b, moves);
	free(move_c);
	return (1);
}
