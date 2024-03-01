/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:04:28 by mapichec          #+#    #+#             */
/*   Updated: 2024/03/01 15:12:24 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (*stack_a == NULL)
		return ;
	if ((*stack_a)->content == (*stack_b)->content)
	{
		(*stack_a) = (*stack_a)->next;
		(*stack_a)->pre = NULL;
		(*stack_b)->next = NULL;
		ft_printf("pb\n");
		return ;
	}
	tmp = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	(*stack_a)->pre = NULL;
	tmp->next = (*stack_b);
	(*stack_b)->pre = tmp;
	tmp->pre = NULL;
	(*stack_b) = tmp;
	posix_gen(stack_a);
	posix_gen(stack_b);
	ft_printf("pb\n");
	return ;
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (*stack_b == NULL)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	if ((*stack_b))
		(*stack_b)->pre = NULL;
	tmp->next = (*stack_a);
	(*stack_a)->pre = tmp;
	tmp->pre = NULL;
	(*stack_a) = tmp;
	posix_gen(stack_a);
	posix_gen(stack_b);
	ft_printf("pa\n");
	return ;
}