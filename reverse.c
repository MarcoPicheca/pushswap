/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:04:55 by mapichec          #+#    #+#             */
/*   Updated: 2024/02/09 13:05:01 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*penultimo(t_list *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

int	rra(t_list **stack_a, int flag)
{
	t_list	*last;
	t_list	*tmp;

	if (ft_lstsize((*stack_a)) <= 1)
		return (1);
	if (ft_lstsize((*stack_a)) == 2)
	{
		ft_printf("rra\n");
		return (sa(stack_a, 1));
	}
	tmp = penultimo((*stack_a));
	last = ft_lstlast((*stack_a));
	last->next = (*stack_a);
	tmp->next = NULL;
	(*stack_a) = last;
	if (flag == 0)
		ft_printf("rra\n");
	posix_gen(stack_a);
	return (0);
}

int	rrb(t_list **stack_b, int flag)
{
	t_list	*last;
	t_list	*tmp;

	if (ft_lstsize((*stack_b)) <= 1)
		return (1);
	if (ft_lstsize((*stack_b)) == 2)
	{
		ft_printf("rrb\n");
		return (sa(stack_b, 1));
	}
	tmp = penultimo((*stack_b));
	last = ft_lstlast((*stack_b));
	last->next = (*stack_b);
	tmp->next = NULL;
	(*stack_b) = last;
	if (flag == 0)
		ft_printf("rrb\n");
	posix_gen(stack_b);
	return (0);
}

int	rrr(t_list **stack_a, t_list **stack_b)
{
	if (rra(stack_a, 1) || rrb(stack_b, 1))
		return (1);
	posix_gen(stack_a);
	ft_printf("rrr\n");
	return (0);
}