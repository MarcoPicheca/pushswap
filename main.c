/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:01:32 by mapichec          #+#    #+#             */
/*   Updated: 2024/02/05 18:45:39 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_to_stack(char *arg, t_list **stack_a, t_list **stack_b)
{
	t_list	*node;

	
	if (ft_strlen(arg) > 11)
		return (1);
	if (!(*stack_b))
		stack_b = NULL;
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

int	split_add_stack(char *arg, t_list **stack_a, t_list **stack_b)
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
		if (add_to_stack(split[i], stack_a, stack_b))
		{
			ft_printf("ERR: creazione stack");
			free_matrix(split);
			return (1);
		}
		i++;
	}
	return (0);
}

int	gen_stack(t_list **stack_a, t_list **stack_b, char **av)
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
			if (split_add_stack(av[i], stack_a, stack_b))
				return (1);
		}
		else
		{
			if (add_to_stack(av[i], stack_a, stack_b))
				return (1);
		}
		i++;
	}
	return (0);
}

void	ft_print_list(t_list **stack_a)
{
	t_list *node;
	int i = 0;

	node = (*stack_a);
	while (node != NULL)
	{
		ft_printf("nodo[%d] = %d\n", i, node->content);
		node = node->next;
		i++;		
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (0);
	if (gen_stack(&stack_a, &stack_b, av) == 1)
	{
		ft_free_stack(&stack_a, &stack_b);
		return (0);
	}
	if (check_double(&stack_a, &stack_b))
		return (0);
	ft_print_list(&stack_a);
	return (0);
}