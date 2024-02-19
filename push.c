/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:04:28 by mapichec          #+#    #+#             */
/*   Updated: 2024/02/19 14:14:19 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (*stack_a == NULL)
		return ;
	tmp = (*stack_a);
	if (!stack_b || !(*stack_b))
	{
		(*stack_b) = ft_lstnew((*stack_a)->content);
		(*stack_a) = (*stack_a)->next;
		free(tmp);
		ft_printf("pb\n");
		return ;
	}
	tmp = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	tmp->next = (*stack_b);
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
	tmp->next = *stack_a;
	*stack_a = tmp;
	posix_gen(stack_a);
	posix_gen(stack_b);
	ft_printf("pa\n");
	return ;
}