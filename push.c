#include "push_swap.h"
void	pa_swap(t_list *stack_a, t_list *stack_b)
{
	t_list	*tmp;

	if (stack_b == NULL)
		return ;
	tmp = stack_b;
	stack_b = stack_b->next;
	tmp->next = stack_a;
	stack_a = tmp;
	write(1, "pa\n", 3);
	return ;	
}

void	pb_swap(t_list *stack_a, t_list *stack_b)
{
	t_list	*tmp;

	if (stack_a == NULL)
		return ;
	tmp = stack_a;
	stack_a = stack_a->next;
	tmp->next = stack_b;
	stack_b = tmp;
	write(1, "pb\n", 3);
	return ;
}