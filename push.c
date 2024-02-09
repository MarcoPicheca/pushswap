/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:04:28 by mapichec          #+#    #+#             */
/*   Updated: 2024/02/09 12:59:42 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*node_a;

	node_a = (*stack_a);
	if (stack_b == NULL)
	{
		(*stack_a)->next = node_a->next;
		node_a->next = NULL;
		(*stack_b)->next = node_a;
	}
	(*stack_a)->next = node_a->next;
	node_a->next = (*stack_b)->next;
	(*stack_b)->next = node_a;
	ft_printf("pb\n");
	posix_gen(stack_a);
	posix_gen(stack_b);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*node_b;

	node_b = (*stack_b);
	if (stack_a == NULL)
	{
		(*stack_b)->next = node_b->next;
		node_b->next = NULL;
		(*stack_a)->next = node_b;
	}
	(*stack_b)->next = node_b->next;
	node_b->next = (*stack_a)->next;
	(*stack_a)->next = node_b;
	ft_printf("pa\n");
	posix_gen(stack_a);
	posix_gen(stack_b);
}