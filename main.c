/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:01:32 by mapichec          #+#    #+#             */
/*   Updated: 2024/03/04 18:17:41 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_to_stack(char *arg, t_list **stack_a)
{
	t_list	*node;

	
	if (ft_strlen(arg) > 11)
		return (1);
	if (ft_strlen(arg) == 11 || ft_strlen(arg) == 10)
	{
		if (check_max_min(arg))
			return (1);
	}
	node = ft_lstnew(ft_atoi(arg));
	if (!node)
	{
		ft_printf("ERR: creazione stack");
		return (1);		
	}
	ft_lstadd_back(stack_a, node);
	return (0);
}

int	split_add_stack(char *arg, t_list **stack_a)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(arg, 32);
	if (!split)
	{
		ft_printf("ERR: creazione stack");
		return (1);
	}
	while (split[i] != NULL)
	{
		if (add_to_stack(split[i], stack_a))
		{
			ft_printf("ERR: creazione stack");
			free_matrix(split);
			return (1);
		}
		i++;
	}
	free_matrix(split);
	return (0);
}

int	gen_stack(t_list **stack_a, char **av)
{
	int		i;
	
	i = 1;
	while (av[i])
	{
		if (ft_isdigit(av[i]))
		{
			ft_printf("ERR: caratteri non numerici, spazi o segni");
			return (1);
		}
		if (ft_isspace(av[i]))
		{
			if (split_add_stack(av[i], stack_a))
				return (1);
		}
		else
		{
			if (add_to_stack(av[i], stack_a))
				return (1);
		}
		i++;
	}
	return (0);
}

void	ft_print_list(t_list **stack_a, t_list **stack_b)
{
	t_list *node;
	t_list *node_b;
	int i = 0;

	node = (*stack_a);
	node_b = (*stack_b);
	ft_printf("\nlistaccia\n");
	while (node != NULL || node_b != NULL)
	{
		if (node)
		{
			ft_printf("STACK_A : nodo[%d] = pre[%p]", node->posix, node->content);
			node = node->next;
		}
		if (!node)
			ft_printf("\t\t\t");
		if (node_b)
		{
			ft_printf("\tSTACK_B : nodo[%d] = pre[%p]\n", node_b->posix, node_b->content);
			node_b = node_b->next;
		}
		else
			ft_printf("\n");
		i++;
	}
}

/*
TODO:	- RIGUARDA LE SA SB SS PER IL PUNTATORE AL NODO PRE
		- problematiche varie sulle mosse da riguardare sui puntatori a nodo pre
		- i movements sembrerebbe che siano corretti		
*/

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		max_lis;

	stack_a = NULL;
	if (ac == 1)
		return (0);
	if (gen_stack(&stack_a, av) == 1)
	{
		ft_free_stack(&stack_a, NULL);
		return (0);
	}
	stack_b = NULL;
	// ft_print_list(&stack_a, &stack_b);
	if (check_double(&stack_a, NULL) || check_sequence(&stack_a))
		return (0);
	if (ft_lstsize((stack_a)) <= 5
		&& lst_less_5(&stack_a, &stack_b, ft_lstsize(stack_a)))
		return (0);
	max_lis = gen_lis(&stack_a);
	// gen_lis(&stack_a);
	from_a_to_b(&stack_a, &stack_b, max_lis);
	return (0);
}
