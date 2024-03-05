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
			ft_printf("ERR: creazione lista mosse\n");
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
	while (node != NULL)
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

void	list_move_a(t_moves **mov, t_list **stack_b, t_list **stack_a)
{
	t_moves	*move;
	t_list	*node_b;

	move = (*mov);
	node_b =(*stack_b);
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
		else if (move->move_b < 0 && move->move_a < 0 && move->move_b < move->move_a)
			move->move_c = (move->move_b * -1) - (move->move_a * -1);
		else if (move->move_b < 0 && move->move_a < 0 && move->move_b >= move->move_a)
			move->move_c = (move->move_a * -1) - (move->move_b * -1);
		else if (move->move_b >= 0 && move->move_a >= 0 && move->move_b >= move->move_a)
			move->move_c = move->move_b - move->move_a;
		else if (move->move_b >= 0 && move->move_a >= 0 && move->move_b < move->move_a)
			move->move_c = move->move_a - move->move_b;
		move = move->next;
	}
	return (0);
}

void	from_b_to_a(int a, int b, t_list **stack_a, t_list **stack_b)
{
	while (a != 0 || b != 0)
	{
		if (b > 0 && a > 0)
		{
			rr(stack_a, stack_b);
			b--;
			a--;
		}
		else if (b < 0 && a < 0)
		{
			rrr(stack_a, stack_b);
			b++;
			a++;
		}
		else if (b < 0 && a == 0)
		{
			rrb(stack_b, 0);
			b++;
		}
		else if (a < 0 && b == 0)
		{
			rra(stack_a, 0);
			a++;
		}
		else if (b > 0 && a == 0)
		{
			rb(stack_b, 0);
			b--;
		}
		else if (a > 0 && b == 0)
		{
			ra(stack_a, 0);
			a--;			
		}
		else if (a < 0 && b > 0)
		{
			rra(stack_a, 0);
			rb(stack_b, 0);
			a++;
			b--;
		}
		else if (a > 0 && b < 0)
		{
			rrb(stack_b, 0);
			ra(stack_a, 0);
			a--;
			b++;
		}
		else if (a == 0 && b == 0)
			break;
	}
	pa(stack_a, stack_b);
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
		// while (mov != NULL)
		// {
		// 	ft_printf("move_a = %d\t", mov->move_a);
		// 	ft_printf("move_b = %d\t", mov->move_b);
		// 	ft_printf("move_c = %d\n", mov->move_c);
		// 	mov = mov->next;
		// }
		// exit(0);
		free_mov_list(&mov);
		mov = NULL;
	}
	// ft_print_list(stack_a, stack_b);
	return (1);
}
