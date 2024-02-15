/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:02:23 by mapichec          #+#    #+#             */
/*   Updated: 2024/02/09 18:41:44 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	from_a_to_b(t_list **stack_a, t_list **stack_b, int max_lis)
{
	t_list	*node;
	t_list	*node_1;

	node = ft_lstlast((*stack_a));
	while (node != NULL)
	{
		if (node->lis == max_lis && node)
			break ;
		node = node->pre;
	}
	while (node)
	{
		node_1 = node->pre;
		if (node_1->posix == node->prev)
		{
			node->lis = 0;
			node = node_1;
		}
		node_1 = node_1->pre;
	}
}