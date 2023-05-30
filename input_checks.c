#include "push_swap.h"

int	ft_check(char *argv)
{
	int	i;
	i = 0;

	while (argv[i])
		if ((argv[i] >= '0' && argv[i] <= '9') || argv[i] == 45)
			i++;
		else
			return(1);
	return (0);
}

int	check_double(t_list *stack_a)
{
	t_list	*tmp;
	t_list	*head;

	tmp = stack_a;
	head = stack_a;
	while (head != NULL)
	{
		while (tmp->content != head->content && tmp != NULL)
			tmp = tmp->next;
		if (tmp->content == head->content)
			return (1);
		else
			tmp = stack_a->next;
		head = head-> next;
	}
	return (0);
}

void	ft_free_error(t_list *stack_a, t_list *stack_b)
{

	free (stack_a);
	free (stack_b);
	exit (0);
}

int	correct_combo(t_list *stack_a)
{
	while (stack_a != NULL)
	{
		if (stack_a->content < stack_a->next->content)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}