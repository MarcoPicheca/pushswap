/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:04:28 by mapichec          #+#    #+#             */
/*   Updated: 2024/03/04 18:09:39 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	duplicate_node(t_list **stack_a, t_list **stack_b)
{
	t_list	*node;
	t_list	*node_1;

	node = ft_lstnew((*stack_a)->content);
	if (!node)
	{
		ft_printf("ERR: creazione stack_b");
		ft_free_stack(stack_a, stack_b);
		return (1);		
	}
	node_1 = (*stack_a)->next;
	free(*stack_a);
	(*stack_a) = node_1;
	node_1->pre = NULL;
	ft_lstadd_back(stack_b, node);
	return (0);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (*stack_a == NULL)
		return ;
	if (!stack_b || !(*stack_b))
	{
		duplicate_node(stack_a, stack_b);
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

	if ((*stack_b) == NULL)
		return ;
	tmp = (*stack_b);
	(*stack_b) = (*stack_b)->next;
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