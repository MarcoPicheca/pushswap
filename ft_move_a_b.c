/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_a_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:02:23 by mapichec          #+#    #+#             */
/*   Updated: 2024/02/20 15:51:51 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_mov(t_list **stack_a)
{
	t_list			*node_a;
	int				pos;
	long long		g;

	g = 2147483648;
	pos = -1;
	node_a = (*stack_a);
	while (node_a != NULL)
	{
		if (node_a->content < g)
		{
			g = node_a->content;
			pos = node_a->posix;
		}
		node_a = node_a->next;
	}
	return (pos);
}

int	find_move_b(int cont, t_list **stack_a)
{
	t_list			*node_a;
	int				pos;
	long long		g;

	g = 2147483648;
	pos = -1;
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
	if (pos == -1)
		pos = find_max_mov(stack_a);
	if (pos < (ft_lstsize((*stack_a)) / 2))
		return (pos);
	if (ft_lstsize((*stack_a)) % 2 != 0
		&& pos == (ft_lstsize((*stack_a)) / 2))
		return (pos);
	else if (pos >= (ft_lstsize((*stack_a)) / 2))
		return (-1 * (ft_lstsize((*stack_a)) - pos));
	return (0);
}

int	gen_move_a(int *move_a, t_list **stack_a, t_list **stack_b)
{
	t_list	*node_b;
	int		i;

	node_b = (*stack_b);
	i = 0;
	while (node_b != NULL)
	{
		move_a[i] = find_move_b(node_b->content, stack_a);
		i++;
		node_b = node_b->next;
	}
	return (1);
}

int	gen_move_b(int *move_b, t_list **stack_b)
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
			move_b[i++] = half++;
		if (ft_lstsize((*stack_b)) % 2 != 0
			&& i == (ft_lstsize((*stack_b)) / 2))
			move_b[i++] = half;
		else if (i >= (ft_lstsize((*stack_b)) / 2))
			move_b[i++] = -1 * (half--);
		node = node->next;
	}
	return (1);
}

int	mov_a_mov_b(t_list **stack_a, t_list **stack_b)
{
	int	*move_a;
	int	*move_b;
	int	*move_c;

	while (stack_b != NULL && (*stack_b))
	{
		move_a = malloc(sizeof(int) * ft_lstsize((*stack_b)));
		move_b = malloc(sizeof(int) * ft_lstsize((*stack_b)));
		move_c = malloc(sizeof(int) * ft_lstsize((*stack_b)));
		if (!move_a || !move_c || !move_b)
			return (0);
		gen_move_b(move_b, stack_b);
		gen_move_a(move_a, stack_a, stack_b);
		ft_move_c(move_a, move_b, move_c, stack_a, stack_b);
		// ft_print_list(stack_a, stack_b);
		free_moves(move_a, move_b, move_c);	
	}
	return (1);
}
