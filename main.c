/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:01:32 by mapichec          #+#    #+#             */
/*   Updated: 2024/03/21 13:43:42 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_to_stack(char *arg, t_list **stack_a)
{
	t_list	*node;

	while (*arg == '0')
		arg++;
	if (ft_strlen(arg) > 11)
		return (1);
	if (ft_strlen(arg) == 11 || ft_strlen(arg) == 10)
	{
		if (check_max_min(arg))
			return (1);
	}
	node = ft_lstnew(ft_atoi(arg));
	if (!node)
		return (1);
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
		return (1);
	}
	while (split[i] != NULL)
	{
		if (add_to_stack(split[i], stack_a))
		{
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

static void	main_2(t_list **stack_a, t_list **stack_b)
{
	int	max_lis;

	max_lis = gen_lis(stack_a);
	from_a_to_b(stack_a, stack_b, max_lis);
	adjust_a(stack_a);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	if (ac == 1)
		return (0);
	if (gen_stack(&stack_a, av) == 1)
	{
		if (stack_a)
			ft_free_stack(&stack_a, NULL);
		ft_printf("Error\n");
		return (0);
	}
	stack_b = NULL;
	if (check_double(&stack_a, NULL) || check_sequence(&stack_a))
		return (0);
	if (ft_lstsize((stack_a)) <= 5
		&& lst_less_5(&stack_a, &stack_b, ft_lstsize(stack_a)))
		return (0);
	fill_stack(&stack_a);
	main_2(&stack_a, &stack_b);
	check_sequence(&stack_a);
	return (0);
}
