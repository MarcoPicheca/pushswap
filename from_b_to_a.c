/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:02:23 by mapichec          #+#    #+#             */
/*   Updated: 2024/03/04 17:21:12 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rr_or_rrr(int *a, int *b, t_list **stack_a, t_list **stack_b)
{
	if ((*b) > 0 && (*a) > 0)
	{
		rr(stack_a, stack_b);
		(*b)--;
		(*a)--;
	}
	else if ((*b) < 0 && (*a) < 0)
	{
		rrr(stack_a, stack_b);
		(*b)++;
		(*a)++;
	}
}

static void	rra_or_rrb(int *a, int *b, t_list **stack_a, t_list **stack_b)
{
	if ((*b) < 0 && (*a) == 0)
	{
		rrb(stack_b, 0);
		(*b)++;
	}
	else if ((*a) < 0 && (*b) == 0)
	{
		rra(stack_a, 0);
		(*a)++;
	}
}

static void	ra_or_rb(int *a, int *b, t_list **stack_a, t_list **stack_b)
{
	if ((*b) > 0 && (*a) == 0)
	{
		rb(stack_b, 0);
		(*b)--;
	}
	else if ((*a) > 0 && (*b) == 0)
	{
		ra(stack_a, 0);
		(*a)--;
	}
}

static void	else_rotation(int *a, int *b, t_list **stack_a, t_list **stack_b)
{
	if ((*a) < 0 && (*b) > 0)
	{
		rra(stack_a, 0);
		rb(stack_b, 0);
		(*a)++;
		(*b)--;
	}
	else if ((*a) > 0 && (*b) < 0)
	{
		rrb(stack_b, 0);
		ra(stack_a, 0);
		(*a)--;
		(*b)++;
	}
}

void	from_b_to_a(int a, int b, t_list **stack_a, t_list **stack_b)
{
	while (a != 0 || b != 0)
	{
		if ((b > 0 && a > 0) || (b < 0 && a < 0))
			rr_or_rrr(&a, &b, stack_a, stack_b);
		else if ((b < 0 && a == 0) || (a < 0 && b == 0))
			rra_or_rrb(&a, &b, stack_a, stack_b);
		else if ((b > 0 && a == 0) || (a > 0 && b == 0))
			ra_or_rb(&a, &b, stack_a, stack_b);
		else if ((a < 0 && b > 0) || (a > 0 && b < 0))
			else_rotation(&a, &b, stack_a, stack_b);
		else if (a == 0 && b == 0)
			break ;
	}
	pa(stack_a, stack_b);
}
