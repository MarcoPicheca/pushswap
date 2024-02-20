/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:02:23 by mapichec          #+#    #+#             */
/*   Updated: 2024/02/20 15:52:59 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	from_a_to_b2(t_list *node, int max_lis)
{
	t_list	*node_1;

	while (node != NULL)
	{
		if (node->lis == max_lis && node)
			break ;
		node = node->pre;
	}
	node_1 = node->pre;
	node->lis = 0;
	while (node)
	{
		while (node->prev != node_1->posix && node_1)
			node_1 = node_1->pre;
		if (!node_1 || node_1->prev == -1)
		{
			node_1->lis = 0;
			return ;
		}
		node_1->lis = 0;
		node = node_1;
		node_1 = node->pre;
	}
}

int	lis_zero(t_list **stack_a)
{
	t_list	*node;

	node = (*stack_a);
	while (node != NULL)
	{
		if (node->lis != 0)
			return (1);
		node = node->next;
	}
	return (0);
}

int	possible_sa(t_list **stack)
{
	t_list	*node;

	node = (*stack)->next;
	if ((*stack)->content > node->content
		&& node->next != NULL)
	{
		if (node->next->content > (*stack)->content)
		{
			(*stack)->lis = 0;
			sa(stack, 0);
			return (1);
		}
		else
			return (0);
	}
	return (0);
}

int	from_a_to_b(t_list **stack_a, t_list **stack_b, int max_lis)
{
	t_list	*node;

	node = ft_lstlast((*stack_a));
	from_a_to_b2(node, max_lis);
	while (lis_zero(stack_a))
	{
		if ((*stack_a)->lis != 0 && !possible_sa(stack_a))
			pb(stack_a, stack_b);
		else
			rra(stack_a, 0);
	}
	if (!mov_a_mov_b(stack_a, stack_b))
	{
		ft_free_stack(stack_a, stack_b);
		return (1);
	}
	return (0);
}