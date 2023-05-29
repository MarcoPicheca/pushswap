#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*t;

	t = (t_list *)malloc(sizeof(*t));
	if (!t)
		return (NULL);
	t->content = content;
	t->next = NULL;
	return (t);
}