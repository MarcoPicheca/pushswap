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

int	alloc_moves(int ***moves, t_list **stack_a, t_list **stack_b)
{
	(*moves) = (int **)malloc(sizeof(int *) * 2);
	if (!moves)
	{
		ft_free_stack(stack_a, stack_b);
		free_matrix2(*moves);
		return (0);
	}
	(*moves)[0] = (int *)malloc(sizeof(int) * ft_lstsize((*stack_b)));
	(*moves)[1] = (int *)malloc(sizeof(int) * ft_lstsize((*stack_b)));
	if (!moves[0] || !moves[1])
	{
		ft_free_stack(stack_a, stack_b);
		free_matrix2(*moves);
		return (0);
	}
	return (1);
}

void	gen_moves(int **moves, t_list **stack_a, t_list **stack_b)
{
	int		half;
	int		i;
	t_list	*node;

	node = (*stack_b);
	half = 0;
	i = 0;
	while (node != NULL)
	{
		if (i < (ft_lstsize((*stack_b)) / 2))
			moves[0][i++] = half++;
		if (ft_lstsize((*stack_b)) % 2 != 0
			&& i == (ft_lstsize((*stack_b)) / 2))
			moves[0][i++] = half;
		else if (i >= (ft_lstsize((*stack_b)) / 2))
			moves[0][i++] = -1 * (half--);
		node = node->next;
	}
	return ;
}

int	mov_a_mov_b(t_list **stack_a, t_list **stack_b)
{
	int	**moves;
	t_list *node = (*stack_a);
	int i = 0;

	moves = NULL;
	while (stack_b != NULL)
	{
		if (!alloc_moves(&moves, stack_a, stack_b))
			return (0);
		gen_moves(moves, stack_a, stack_b);
		while (i < ft_lstsize((*stack_a)) && node)
		{
			printf("nodo [%d] = move_a [%d] = num [%d]\n", node->content, moves[0][i++], node->posix);
			node = node->next;
		}
		return (0);
		// actual_movements(stack_a, stack_b, moves);
		free_matrix2(moves);
	}
	return (1);
}
