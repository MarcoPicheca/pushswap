/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:01:32 by mapichec          #+#    #+#             */
/*   Updated: 2024/02/03 11:43:39 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_list **stack_a, t_list **stack_b)
{
	t_list	*node;

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

int	add_to_stack(char *arg, t_list **stack_a, t_list **stack_b)
{
	t_list	*node;

	node = ft_lstnew(ft_atoi(arg));
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

/* TODO: 
		- provare se il controllo dell'input e se la creazione 
			della lista funziona
		- sistemare questione makefile e compilazione*/

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (0);
	while (av[i])
	{
		// controllo che ci siano solo numeri, '+', '-' o spazi negli args
		if (ft_isdigit(av[i]))
		{
			ft_free_stack(&stack_a, &stack_b);
			return (ft_printf("ERR: caratteri non numerici, spazi o segni"));
		}
		// controlla se ci sono spazi enell'argomento e lo manda a
		// splittare e aggiungere alla lista
		if (ft_isspace(av[i]))
		{
			if (split_add_stack(av[i], &stack_a, &stack_b))
				return (ft_printf("ERR: creazione stack"));
		}
		// aggiunta a stack in altri casi
		else
		{
			if (add_to_stack(av[i], &stack_a, &stack_b))
				return (ft_printf("ERR: creazione stack"));
		}
		i++;
	}
	return (0);
}