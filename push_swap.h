/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicheca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:22:28 by mpicheca          #+#    #+#             */
/*   Updated: 2023/05/02 10:34:33 by mpicheca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <signal.h>
# include <stdio.h>

typedef struct s_list
{
	int			content;
	struct s_list	*next;
}	t_list;
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstnew(int content);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	rra_swap(t_list **stack_a);
void	rrb_swap(t_list **stack_b);
void	rrr_swap(t_list **head, t_list **stack_a);
void	ra_swap(t_list **stack_a);
void	rb_swap(t_list **stack_b);
void	rr_swap(t_list **stack_a, t_list **stack_b);
void	sa_swap(t_list **stack_a);
void	sb_swap(t_list **stack_b);
void	ss_swap(t_list **stack_a, t_list **stack_b);
void	pa_swap(t_list **stack_a, t_list **stack_b);
void	pb_swap(t_list **stack_a, t_list **stack_b);


#endif

