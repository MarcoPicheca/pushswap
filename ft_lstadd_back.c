#include "push_swap.h"

static t_list	*ft_ziolast(t_list *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst)
	{
		if (*lst)
		{
			last = ft_ziolast(*lst);
			last->next = new;
		}
		else
			*lst = new;
	}
}
