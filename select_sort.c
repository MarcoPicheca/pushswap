/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:12:27 by mapichec          #+#    #+#             */
/*   Updated: 2024/03/12 16:43:53 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_2_in_b(t_list **stack_a, t_list **stack_b)
{
	int	move;

	move = find_in_a((*stack_b)->content, stack_a);
	while (move != 0)
	{
		if (move < 0)
		{
			rra(stack_a, 0);
			move++;
		}
		else if (move > 0)
		{
			ra(stack_a, 0);
			move--;
		}
	}
	pa(stack_a, stack_b);
	return (1);
}
