/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_nbr2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:04:28 by mapichec          #+#    #+#             */
/*   Updated: 2024/02/09 12:59:42 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	corr_sequence(t_list **stack_a)
{
	int		g;
	int		f;
	t_list	*node;

	g = INT_MAX;
	node = (*stack_a);
	while (node != NULL)
	{
		if (node->content < g)
		{
			g = node->content;
			f = node->posix;
		}
		node = node->next;
	}
	sequence_roll(stack_a, f, g);
}

int	first_roll(t_list **stack_a, t_list *node)
{
	int	i;

	i = 0;
	while ((*stack_a)->content != node->content)
	{
		if (node->posix <= ft_lstsize((*stack_a)) / 2)
		{
			ra(stack_a, 0);
			i++;
		}
		else if (node->posix > ft_lstsize((*stack_a)) / 2)
		{
			rra(stack_a, 0);
			i--;
		}
	}
	return (i);
}

void	second_roll(t_list **stack_a, int i)
{
	while (i != 0)
	{
		if (i <= 0)
		{
			ra(stack_a, 0);
			i++;
		}
		else if (i >= 0)
		{
			rra(stack_a, 0);
			i--;
		}
	}
}

void	sequence_roll(t_list **stack_a, int i, int g)
{
	while ((*stack_a)->content != g)
	{
		if (i <= ft_lstsize((*stack_a)) / 2)
			ra(stack_a, 0);
		else if (i > ft_lstsize((*stack_a)) / 2)
			rra(stack_a, 0);
	}
}