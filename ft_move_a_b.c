/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_a_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:02:23 by mapichec          #+#    #+#             */
/*   Updated: 2024/02/19 16:16:11 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	alloc_moves(int ***moves, t_list **stack_a, t_list **stack_b)
{
	(*moves) = (int **)malloc(sizeof(int *) * 2);
	if (!moves)
	{
		ft_free_stack(stack_a, stack_b);
		return (0);
	}
	(*moves)[0] = (int *)malloc(sizeof(int) * ft_lstsize((*stack_b)));
	(*moves)[1] = (int *)malloc(sizeof(int) * ft_lstsize((*stack_b)));
	if (!(*moves)[0] || !(*moves)[1])
	{
		ft_free_stack(stack_a, stack_b);
		free_matrix2(*moves);
		return (0);
	}
	return (1);
}

int	find_move_b(int cont, t_list **stack_a)
{
	t_list			*node_a;
	int				pos;
	long long		g;

	g = 2147483648;
	node_a = (*stack_a);
	while (node_a != NULL)
	{
		if (node_a->content < g && node_a->content > cont)
		{
			g = node_a->content;
			pos = node_a->posix;
		}
		node_a = node_a->next;
	}
	if (pos < (ft_lstsize((*stack_a)) / 2))
		return (pos);
	if (ft_lstsize((*stack_a)) % 2 != 0
		&& pos == (ft_lstsize((*stack_a)) / 2))
		return (pos);
	else if (pos >= (ft_lstsize((*stack_a)) / 2))
		return (-1 * (ft_lstsize((*stack_a)) - pos));
	return (0);
}

int	move_b(int **moves, t_list **stack_a, t_list **stack_b)
{
	t_list	*node_b;
	int		i;

	node_b = (*stack_b);
	i = 0;
	while (node_b != NULL)
	{
		moves[1][i] = find_move_b(node_b->content, stack_a);
		i++;
		node_b = node_b->next;
	}
	if (!ft_move_c(moves, stack_a, stack_b))
	{
		ft_free_stack(stack_a, stack_b);
		free_matrix2(moves);
		return (0);
	}
	return (1);
}

int	gen_moves(int **moves, t_list **stack_a, t_list **stack_b)
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
	if (!move_b(moves, stack_a, stack_b))
		return (0);	
	return (1);
}

int	mov_a_mov_b(t_list **stack_a, t_list **stack_b)
{
	int	**moves;
	// t_list *node = (*stack_b);
	// int i = 0;

	moves = NULL;
	while (stack_b != NULL && (*stack_b))
	{
		if (!alloc_moves(&moves, stack_a, stack_b) || !gen_moves(moves, stack_a, stack_b))
			return (0);
		// while (i < ft_lstsize((*stack_b)) && node)
		// {
		// 	printf("nodo [%d] = move_b [%d] = move_a [%d] = num [%d]\n", node->content, moves[1][i], moves[0][i], node->posix);
		// 	node = node->next;
		// 	i++;
		// }
		free_matrix2(moves);
	}
	return (1);
}
