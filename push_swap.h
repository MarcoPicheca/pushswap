/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:30:57 by mapichec          #+#    #+#             */
/*   Updated: 2024/02/06 16:26:10 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_printf/ft_printf.h"

typedef struct s_list
{
	int		content;
	int		lis;
	int		posix;
	int		prev;
	struct s_list	*next;
}				t_list;

t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_atoi(const char *nptr);
int		ft_isdigit(char *str);
int		ft_isspace(char *str);
char	**ft_split(const char *s, char c);
size_t	ft_strlen(const char *str);
void	ft_free_stack2(t_list **stack_b);
void	ft_free_stack(t_list **stack_a, t_list **stack_b);
int		gen_stack(t_list **stack_a, t_list **stack_b, char **av);
int		check_double(t_list **stack_a, t_list **stack_b);
int		check_max_min(char *str);
void	free_matrix(char **split);
int		gen_lis(t_list **stack_a, t_list **stack_b);
void	fill_stack(t_list **stack_a);
int		ft_find_prev(t_list **stack_a, t_list *node_lis, int lis, int posix);

#endif