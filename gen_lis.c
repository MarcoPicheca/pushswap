/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_lis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:27:26 by mapichec          #+#    #+#             */
/*   Updated: 2024/02/09 12:59:18 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack(t_list **stack_a)
{
	t_list	*node;
	int		i;

	node = (*stack_a);
	i = 0;
	while (node != NULL)
	{
		node->lis = 1;
		node->posix = i++;
		node->prev = -1;
		node = node->next;
	}	
}

void	posix_gen(t_list **stack)
{
	t_list	*node;
	int		i;

	node = (*stack);
	i = 0;
	while (node != NULL)
	{
		node->posix = i++;
		node = node->next;
	}	
}

int	ft_find_prev(t_list **stack_a, t_list *node_lis, int lis, int posix)
{
	t_list	*node;
	int		tmp;

	node = (*stack_a);
	tmp = INT_MAX;
	while (node->posix < posix && node->next)
	{
		if (node->content < tmp && node->lis < lis
			&& node->content < node_lis->content
			&& node->lis > node_lis->lis - 2)
			tmp = node->content;
		node = node->next;
	}
	node = (*stack_a);
	while (node->content != tmp && node->next)
		node = node->next;
	return (node->posix);
}

int	gen_lis(t_list **stack_a)
{
	t_list	*node;
	t_list	*node1;
	int		max_lis;
	
	node = (*stack_a);
	max_lis = 0;
	fill_stack(stack_a);
	while (node->next != NULL)
	{
		node1 = node->next;
		while (node1 != NULL)
		{
			if (node1->lis <= node->lis
				&& node->content < node1->content
				&& (node1->lis + 1) >= max_lis)
			{
				node1->lis += 1;
				max_lis = node1->lis;
				node1->prev = ft_find_prev(stack_a, node1, node1->lis
				, node1->posix);
			}
			node1 = node1->next;
		}
		node = node->next;		
	}
	return (max_lis);
}

/* 
0	1	2	3	4	5	6	7	8	9

10  4   8	3	-3	89	78	5	9	2

1	1	2	1	1	3	3	2	3	2

-1	-1	1	-1	-1	2	2	1	2	4 */





