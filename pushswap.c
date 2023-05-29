
#include "push_swap.h"

// int	ft_check(char *argv)
// {
// 	int	i;
// 	i = 0;
// 
// 	while (argv[i])
// 		if ((argv[i] >= '0' && argv[i] <= '9') || argv[i] == 45)
// 			i++;
// 		else
// 			return(1);
// 	return (0);
// }

int	check_double(t_list *stack_a)
{
	t_list	*tmp;
	tmp = stack_a;
	tmp = tmp->next;

	while (stack_a != NULL)
	{
		while (tmp != NULL)
		{
			if (tmp->content != stack_a->content)
			{
				stack_a = stack_a->next;
			}
			else
				return (1);
		}
		stack_a = stack_a->next;
	}
	return (0);
}

t_list	**stackato(char *argv, t_list **stack_a)
{
	t_list	*new_node;
	int	data;
	int	i;
	i = 0;

	while (argv[i])
	{
		if ((argv[i] >= '0' && argv[i] <= '9') || argv[i] == 45)
			i++;
		else
			return(1);
	}
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
	stack_b = NULL;
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
		TODO:/*check_correct (&stack_a) e deve controllare le la sequenza presente è 
		già corretta ad es 1 - 2 - 3*/  
		if (check_double(&stack_a) == 1)
			{
				free (stack_a);
				exit (0);
			}
	}
	if(ft_lstsize(stack_a) <= 5)
		ft_swap5(&stack_a, &stack_b);
	else
		pushami(&stack_a, &stack_b);
	free(stack_b);
	return(stack_a);
}
//		STAMPA DELLA LISTA
		// while (stack_a != NULL)
		// {
		// 	printf("%d\n", stack_a->content);
		// 	stack_a = stack_a->next;
		// }