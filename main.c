/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:01:32 by mapichec          #+#    #+#             */
/*   Updated: 2024/02/03 12:47:48 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_to_stack(char *arg, t_list **stack_a, t_list **stack_b)
{
	t_list	*node;

	node = ft_lstnew(ft_atoil(arg));
	if (!node)
	{
		ft_free_stack(stack_a, stack_b);
		return (1);
	}
	ft_lstadd_back(stack_a, node);
	return (0);
}

int	split_add_stack(char *arg, t_list **stack_a, t_list **stack_b)
{
	char	**split;
	int		i;

	split = ft_split(arg, 32);
	i = 0;
	if (!split)	
	{
		ft_free_stack(stack_a, stack_b);
		return (1);
	}
	while (split[i] != NULL)
	{
		add_to_stack(split[i], stack_a, stack_b);
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
			ft_free_stack(&stack_a, &stack_b);
			ft_printf("ERR: caratteri non numerici, spazi o segni");
			return (1);
		}
		if (ft_isspace(av[i]))
		{
			if (split_add_stack(av[i], &stack_a, &stack_b))
			{
				ft_printf("ERR: creazione stack")
				return (1);
			}
		}
		else
		{
			if (add_to_stack(av[i], &stack_a, &stack_b))
			{
				ft_printf("ERR: creazione stack");
				return (1);
			}
		}
		i++;
	}
	return (0);
}

/* TODO: 
		- creazione check doppi e numeri maggiori MAXITN e minori MININT*/

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (0);
	if (gen_stack(&stack_a, &stack_b, av))
		return (0);
	if (check_double(&stack_a) || check_max_min(&stack_a))
		return (0);
	return (0);
}