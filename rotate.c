/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:05:04 by mapichec          #+#    #+#             */
/*   Updated: 2024/03/04 17:05:01 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_list **stack_a, int flag)
{
	t_list	*testa;
	t_list	*last;

	testa = (*stack_a);
	last = ft_lstlast((*stack_a));
	if (ft_lstsize((*stack_a)) <= 1)
		return (1);
	if (ft_lstsize((*stack_a)) == 2)
	{
		ft_printf("ra\n");
		return (sa(stack_a, 1));
	}
	(*stack_a) = (*stack_a)->next;
	testa->next = NULL;
	testa->pre = last;
	last->next = testa;
	if (flag == 0)
		ft_printf("ra\n");
	posix_gen(stack_a);
	return (0);
}

int	rb(t_list **stack_b, int flag)
{
	t_list	*testa;
	t_list	*last;

	testa = (*stack_b);
	last = ft_lstlast((*stack_b));
	if (!(*stack_b))
		return (1);
	*stack_b = testa->next;
	testa->next = NULL;
	testa->pre = last;
	last->next = testa;
	if (flag == 0)
		ft_printf("rb\n");
	posix_gen(stack_b);
	return (0);
}

int	rr(t_list **stack_a, t_list **stack_b)
{
	if (ra(stack_a, 1) || rb(stack_b, 1))
		return (1);
	ft_printf("rr\n");
	return (0);
}
