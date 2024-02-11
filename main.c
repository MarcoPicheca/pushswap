/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:01:32 by mapichec          #+#    #+#             */
/*   Updated: 2024/02/09 18:44:15 by mapichec         ###   ########.fr       */
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
	int i = 0;

	node = (*stack_a);
	while (node != NULL)
	{
		ft_printf("nodo[%d] = num[%d] = lis [%d] = prev [%d]\n", node->posix, node->content, node->lis, node->prev);
		node = node->next;
		i++;
	}
	if (stack_b)
		stack_b = NULL;
	/* 
	node = (*stack_b);
	ft_printf("\nstack_b %d\n", node->content); */
}

/*
TODO:	problematiche su getione 4 numeri e finire ordinamento a 5 numeri.
		gestione LIS e push. creazione move-a e move-b.
*/

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (0);
	if (gen_stack(&stack_a, av) == 1)
	{
		ft_free_stack(&stack_a, NULL);
		return (0);
	}
	if (check_double(&stack_a, NULL) || check_sequence(&stack_a))
		return (0);
	if (ft_lstsize((stack_a)) <= 5
		&& lst_less_5(&stack_a, &stack_b, ft_lstsize(stack_a)))
	{
		ft_print_list(&stack_a, &stack_b);
		return (0);
	}
	else if (gen_lis(&stack_a, &stack_b))
		return (0);
	return (0);
}