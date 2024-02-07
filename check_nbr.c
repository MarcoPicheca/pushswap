/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:34:30 by mapichec          #+#    #+#             */
/*   Updated: 2024/02/05 15:38:54 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_double(t_list **stack_a, t_list **stack_b)
{
	t_list	*node_1;	
	t_list	*node_2;	

	node_1 = (*stack_a);
	while (node_1->next != NULL)
	{
		node_2 = node_1->next;
		while (node_2)
		{
			if (node_1->content == node_2->content)
			{
				ft_printf("Double numbers\n");
				ft_free_stack(stack_a, stack_b);
				return (1);
			}
			node_2 = node_2->next;
		}
		node_1 = node_1->next;
	}
	return (0);
}

int	max_compare(char *str)
{
	int	i;
	int	max;
	int	nbr;

	if (str[0] == '+')
		i = 1;
	else
		i = 0;
	nbr = 0;
	max = '2' + '1' + '4' + '7' + '4';
	max += '8' + '3' + '6' + '4' + '7';
	while (str[i] != '\0')
	{
		nbr += str[i];
		i++;
	}
	if (nbr > max)
	{
		ft_printf("Numero fuori range interi\n");
		return (1);
	}
	return (0);
}

int	min_compare(char *str)
{
	int	i;
	int	min;
	int	nbr;

	i = 1;
	nbr = 0;
	min = '2' + '1' + '4' + '7' + '4';
	min += '8' + '3' + '6' + '4' + '8';
	while (str[i] != '\0')
	{
		nbr += str[i];
		i++;
	}
	if (nbr > min)
	{
		ft_printf("Numero fuori range interi\n");
		return (1);
	}
	return (0);
}

int	check_max_min(char *str)
{
	if (ft_strlen(str) == 11 && str[0] == '-')
	{
		if (min_compare(str))
			return (1);
	}
	else if (ft_strlen(str) == 10
			|| (ft_strlen(str) == 11 && str[0] == '+'))
	{
		if (max_compare(str))
			return (1);
	}
	else
		return (1);
	return (0);
}

int check_sequence(t_list **stack_a)
{
	t_list	*node;
	t_list	*node1;

	node = (*stack_a);
	node1 = node->next;
	while (node1)
	{
		if (node->content > node1->content)
			return (0);
		node = node->next;
		node1 = node1->next;
	}
	ft_free_stack(stack_a, NULL);
	ft_printf("ERR: correct sequence\n");
	return (1);
}
