/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_moves2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:02:23 by mapichec          #+#    #+#             */
/*   Updated: 2024/03/12 16:26:00 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_mov_list(t_moves **mov, t_list **stack_b)
{
	t_moves	*new;
	int		i;

	i = 0;
	while (i < ft_lstsize((*stack_b)))
	{
		new = (t_moves *)malloc(sizeof(t_moves) * 1);
		if (!new)
		{
			ft_printf("Error\n");
			return (0);
		}
		new->move_a = 0;
		new->move_b = 0;
		new->move_c = 0;
		new->next = NULL;
		ft_lstadd_back2(mov, new);
		i++;
	}
	return (1);
}

void	list_move_b(t_moves **mov)
{
	int		half;
	int		i;
	t_moves	*node;

	node = (*mov);
	half = 0;
	i = 0;
	while (node != NULL )
	{
		if (i < (ft_lstsize2((*mov)) / 2))
			node->move_b = half++;
		if (ft_lstsize2((*mov)) % 2 != 0
			&& i == (ft_lstsize2((*mov)) / 2))
			node->move_b = half;
		else if (i >= (ft_lstsize2((*mov)) / 2))
			node->move_b = -1 * (half--);
		i++;
		node = node->next;
	}
}

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

int	pos_stack(int pos, t_list **stack_a)
{
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

int	find_in_a(int cont, t_list **stack_a)
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
	return (pos_stack(pos, stack_a));
}
