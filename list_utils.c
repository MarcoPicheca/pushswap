/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:41:16 by mapichec          #+#    #+#             */
/*   Updated: 2024/02/09 14:40:41 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list) * 1);
	if (!new)
		return (NULL);
	new->next = NULL;
	new->content = content;
	return (new);
}

int	ft_lstsize(t_list *lst)
{
	t_list	*scorri;
	int		i;

	scorri = lst;
	i = 0;
	while (scorri)
	{
		scorri = scorri->next;
		i++;
	}
	return (i);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*c;

	if (lst)
	{
		if (*lst)
		{
			c = ft_lstlast(*lst);
			c->next = new;
		}
		else
			*lst = new;
	}
	else if (!lst)
		lst = &new;
}