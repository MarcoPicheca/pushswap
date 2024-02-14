/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:30:57 by mapichec          #+#    #+#             */
/*   Updated: 2024/02/09 14:42:52 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"

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
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_atoi(const char *nptr);
int		ft_isdigit(char *str);
int		ft_isspace(char *str);
char	**ft_split(const char *s, char c);
size_t	ft_strlen(const char *str);
void	ft_free_stack2(t_list **stack_b);
void	ft_free_stack(t_list **stack_a, t_list **stack_b);
int		gen_stack(t_list **stack_a, char **av);
int		check_double(t_list **stack_a, t_list **stack_b);
int		check_max_min(char *str);
void	free_matrix(char **split);
int		gen_lis(t_list **stack_a, t_list **stack_b);
void	fill_stack(t_list **stack_a);
int		ft_find_prev(t_list **stack_a, t_list *node_lis, int lis, int posix);
int		check_sequence(t_list **stack_a);
int		lst_less_5(t_list **stack_a, t_list **stack_b, int size);
void	posix_gen(t_list **stack_a);
int		add_to_stack(char *arg, t_list **stack_a);
int		split_add_stack(char *arg, t_list **stack_a);
int		ft_lst_5(t_list **stack_a, t_list **stack_b);
int		ft_lst_3(t_list **stack);
t_list	*find_major(t_list **stack_a, t_list **stack_b);
int		ft_lst_4(t_list **stack_a, t_list **stack_b, int flag);
t_list	*penultimo(t_list *stack);
void	ft_print_list(t_list **stack_a, t_list **stack_b);
int		first_roll(t_list **stack_a, t_list *node);
void	second_roll(t_list **stack_a, int i);
void	corr_sequence(t_list **stack_a);
void	sequence_roll(t_list **stack_a, int i, int g);

// mosse
void	pb(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
int		sa(t_list **stack_a, int flag);
int		sb(t_list **stack_b, int flag);
int		ss(t_list **stack_a, t_list **stack_b);
int		ra(t_list **stack_a, int flag);
int		rb(t_list **stack_b, int flag);
int		rr(t_list **stack_a, t_list **stack_b);
int		rra(t_list **stack_a, int flag);
int		rrb(t_list **stack_b, int flag);
int		rrr(t_list **stack_a, t_list **stack_b);

#endif