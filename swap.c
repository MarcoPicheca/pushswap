/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:05:11 by mapichec          #+#    #+#             */
/*   Updated: 2024/02/09 13:00:55 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_list **stack_a, int flag)
{
	t_list	*node;
	
	if ((*stack_a)->next == NULL || *stack_a == NULL)
		return (1);
	node = (*stack_a)->next;
	(*stack_a)->next = node->next;
	node->next = (*stack_a);
	*stack_a = node;
	if (flag == 0)
		ft_printf("sa\n");
	posix_gen(stack_a);
	return (0);
}

int	sb(t_list **stack_b, int flag)
{
	t_list	*node;
	
	if ((*stack_b)->next == NULL || *stack_b == NULL)
		return (1);
	node = (*stack_b)->next;
	(*stack_b)->next = node->next;
	node->next = (*stack_b);
	*stack_b = node;
	if (flag == 0)
		ft_printf("sb\n");
	posix_gen(stack_b);
	return (0);
}

int	ss(t_list **stack_a, t_list **stack_b)
{
	if (sa(stack_a, 1) || sb(stack_b, 1))
		return (1);
	ft_printf("ss\n");
	return (0);
}