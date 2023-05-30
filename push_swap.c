/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicheca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:34:48 by mpicheca          #+#    #+#             */
/*   Updated: 2023/05/02 11:36:27 by mpicheca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	**stackato(char *argv, t_list **stack_a)
{
	t_list	*new_node;
	int	data;

	data = 0;
	new_node = (t_list *)malloc(sizeof(t_list));
	data = ft_atoi(argv);
	new_node->content = data;
	ft_lstadd_back(stack_a, new_node);
	return(stack_a);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int	i;
	
	i = 1;
	stack_a = (t_list*)malloc((argc * (sizeof(t_list))));
	stack_b = (t_list*)malloc((argc * (sizeof(t_list))));
	if (argc <= 2)
		return(0);
	else
	{
		stack_a->content = ft_atoi(argv[i++]);
		while (i < argc)
		{
			if (stackato(argv[i], &stack_a) == 1)
			{
				free (stack_a);
				exit (0);
			}
			i++;
		}
		if (check_double(stack_a) == 1)
			ft_free_error(&stack_a, &stack_b);
		if (correct_combo(stack_a) == 1)
		{
			write(1, "Correct combo!", 15);
			return (0);
		}
	}
	if(ft_lstsize(stack_a) <= 5)
		ft_swap_5(&stack_a, &stack_b);
	else
		pushami(&stack_a, &stack_b);
	free(stack_b);
	return(0);
}

// STAMPA LISTA
//		while (stack_a != NULL)
//		{
//			printf("%d\n", stack_a->content);
//			stack_a = stack_a->next;
//		}


// int	longest;

// stack a = 40 12 33 45 9 8 10;
// longest = 40;
// int *lis = 40, 45;
// while (stack a != NULL)
// {
// 	if (stack a[i] > longest)
// 	{
// 		longest= stack_a[i];
// 		list[x] = longest;
// 	}
// }

// stack a =  10 40 45  stack  8 9  33 12 

// mov a [0];
   
// mov b [0];
