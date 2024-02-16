/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:16:45 by mapichec          #+#    #+#             */
/*   Updated: 2024/02/06 14:48:11 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack2(t_list **stack_b)
{
	t_list	*node;

	if (!stack_b)
		return ;
	if ((*stack_b) && (*stack_b)->next)
		node = (*stack_b)->next;
	while ((*stack_b) != NULL)
	{
		free((*stack_b));
		if (node)
			(*stack_b) = node;
		if (node && node->next)
			node = node->next;
		else
			node = NULL;
	}
}

void	ft_free_stack(t_list **stack_a, t_list **stack_b)
{
	t_list	*node;

	if (!stack_a)
		return ;
	if ((*stack_a)->next != NULL && (*stack_a))
		node = (*stack_a)->next;
	else
		node = NULL;
	while ((*stack_a))
	{
		free((*stack_a));
		(*stack_a) = NULL;
		if (node)
			(*stack_a) = node;
		if (node && node->next)
			node = node->next;
		else
			node = NULL;
	}
	ft_free_stack2(stack_b);
}

void	free_matrix(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_matrix2(int **moves)
{
	int	i;

	i = 0;
	while (moves[i] != NULL)
	{
		free(moves[i]);
		i++;
	}
	free(moves);
}