/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:41:16 by mapichec          #+#    #+#             */
/*   Updated: 2024/02/09 14:40:41 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize2(t_moves *lst)
{
	t_moves	*scorri;
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

t_moves	*ft_lstlast2(t_moves *lst)
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

void	ft_lstadd_back2(t_moves **lst, t_moves *new)
{
	t_moves	*c;

	if (lst)
	{
		if (*lst)
		{
			c = ft_lstlast2(*lst);
			c->next = new;
			new->prev = c;
		}
		else
		{
			*lst = new;
			new->prev = NULL;
		}
	}
	else if (!lst)
	{
		lst = &new;
		new->prev = NULL;
	}
}
