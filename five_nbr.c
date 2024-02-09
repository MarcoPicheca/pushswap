/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_nbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:02:23 by mapichec          #+#    #+#             */
/*   Updated: 2024/02/09 18:41:44 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lst_3(t_list **stack)
{
	int	one;
	int	two;
	int	three;

	one = (*stack)->content;
	two = (*stack)->next->content;
	three = (*stack)->next->next->content;
	if (one < two && one > three)
		rra(stack, 0);
	else if (one > two && one < three)
		sa(stack, 0);
	else if (one > two && one > three && two < three)
		ra(stack, 0);
	else if (one > two && one > three && two > three)
	{
		ra(stack, 0);
		sa(stack, 0);
	}
	else if (one < three && one < two)
	{
		rra(stack, 0);
		sa(stack, 0);
	}
	return (0);
}

t_list	*find_major(t_list **stack_a, t_list **stack_b)
{
	t_list	*node_a;
	
	node_a = (*stack_a);
	while (node_a != NULL)
	{
		if (node_a->content > (*stack_b)->content)
			return (node_a);
		node_a = node_a->next;
	}
	return (NULL);
}

int	ft_lst_4(t_list **stack_a, t_list **stack_b)
{
	t_list	*node;
	int		i;

	pb(stack_a, stack_b);
	ft_lst_3(stack_a);
	node = find_major(stack_a, stack_b);
	if (node == NULL)
	{
		pa(stack_a, stack_b);
		return (ra(stack_a, 0));
	}
	i = 0;
	while ((*stack_a)->content != node->content)
	{
		ra(stack_a, 0);
		i++;		
	}
	while (i > 0)	
		rra(stack_a, 0);
	return (0);
}

int		lst_less_5(t_list **stack_a, t_list **stack_b, int size)
{
	posix_gen(stack_a);
	if (stack_b)
		stack_b = NULL;
	if (size == 2)
		sa(stack_a, 0);
	if (size == 3)
		ft_lst_3(stack_a);
	if (size == 4)
		ft_lst_4(stack_a, stack_b);
	// if (size == 5)
	// 	return (ft_lst_5(stack_a, stack_b));
	return (1);
}
