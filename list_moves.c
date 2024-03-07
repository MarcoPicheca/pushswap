/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:02:23 by mapichec          #+#    #+#             */
/*   Updated: 2024/03/04 17:48:16 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_move_a(t_moves **mov, t_list **stack_b, t_list **stack_a)
{
	t_moves	*move;
	t_list	*node_b;

	move = (*mov);
	node_b = (*stack_b);
	while (node_b != NULL)
	{
		move->move_a = find_in_a(node_b->content, stack_a);
		move = move->next;
		node_b = node_b->next;
	}
}

int	list_move_c(t_moves **mov)
{
	t_moves	*move;

	move = (*mov);
	while (move != NULL)
	{
		if (move->move_b < 0 && move->move_a >= 0)
			move->move_c = (move->move_b * -1) + move->move_a;
		else if (move->move_b >= 0 && move->move_a < 0)
			move->move_c = (move->move_a * -1) + move->move_b;
		else if (move->move_b < 0 && move->move_a < 0
			&& move->move_b < move->move_a)
			move->move_c = (move->move_b * -1) - (move->move_a * -1);
		else if (move->move_b < 0 && move->move_a < 0
			&& move->move_b >= move->move_a)
			move->move_c = (move->move_a * -1) - (move->move_b * -1);
		else if (move->move_b >= 0 && move->move_a >= 0
			&& move->move_b >= move->move_a)
			move->move_c = move->move_b - move->move_a;
		else if (move->move_b >= 0 && move->move_a >= 0
			&& move->move_b < move->move_a)
			move->move_c = move->move_a - move->move_b;
		move = move->next;
	}
	return (0);
}

int	actual_move(t_list **stack_a, t_list **stack_b, t_moves **mov)
{
	int		g;
	t_moves	*node;
	t_moves	*node_1;

	g = INT_MAX;
	node = (*mov);
	while (node != NULL)
	{
		if (node->move_c < g)
		{
			g = node->move_c;
			node_1 = node;
		}
		node = node->next;
	}
	from_b_to_a(node_1->move_a, node_1->move_b, stack_a, stack_b);
	return (0);
}

int	move_in_list(t_list **stack_a, t_list **stack_b)
{
	t_moves	*mov;

	mov = NULL;
	while (stack_b != NULL && (*stack_b))
	{
		if (!add_mov_list(&mov, stack_b))
			return (0);
		list_move_b(&mov);
		list_move_a(&mov, stack_b, stack_a);
		list_move_c(&mov);
		actual_move(stack_a, stack_b, &mov);
		free_mov_list(&mov);
		mov = NULL;
	}
	return (1);
}
