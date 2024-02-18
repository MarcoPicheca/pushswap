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
	struct s_list	*pre;
}				t_list;

// basic modified lib function
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_atoi(const char *nptr);
int		ft_isdigit(char *str);
int		ft_isspace(char *str);
char	**ft_split(const char *s, char c);
size_t	ft_strlen(const char *str);

// free stack and matrix functions
void	ft_free_stack2(t_list **stack_b);
void	ft_free_stack(t_list **stack_a, t_list **stack_b);
void	free_matrix(char **split);
void	free_matrix2(int **moves);

// generation of the stack
int		gen_stack(t_list **stack_a, char **av);
int		split_add_stack(char *arg, t_list **stack_a);
int		add_to_stack(char *arg, t_list **stack_a);
void	fill_stack(t_list **stack_a);

// basic checks
int		check_double(t_list **stack_a, t_list **stack_b);
int		check_max_min(char *str);
int		check_sequence(t_list **stack_a);

// 3 to 5 elements
int		lst_less_5(t_list **stack_a, t_list **stack_b, int size);
int		ft_lst_5(t_list **stack_a, t_list **stack_b);
int		ft_lst_3(t_list **stack);
int		ft_lst_4(t_list **stack_a, t_list **stack_b, int flag);
t_list	*find_major(t_list **stack_a, t_list **stack_b);
t_list	*penultimo(t_list *stack);
void	ft_print_list(t_list **stack_a, t_list **stack_b);
int		first_roll(t_list **stack_a, t_list *node);
void	second_roll(t_list **stack_a, int i);
void	corr_sequence(t_list **stack_a);
void	sequence_roll(t_list **stack_a, int i, int g);

// moves
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

// lis algorithm
int		gen_lis(t_list **stack_a);
int		ft_find_prev(t_list **stack_a, t_list *node_lis, int lis, int posix);
void	posix_gen(t_list **stack_a);
int		from_a_to_b(t_list **stack_a, t_list **stack_b, int max_lis);
void	from_a_to_b2(t_list *node, int max_lis);
int		possible_sa(t_list **stack);

// move_a_move_b system
int		mov_a_mov_b(t_list **stack_a, t_list **stack_b);
int		alloc_moves(int ***moves, t_list **stack_a, t_list **stack_b);
void	gen_moves(int **moves, t_list **stack_a, t_list **stack_b);
void	move_b(int **moves, t_list **stack_a, t_list **stack_b);
int		find_move_b(int cont, t_list **stack_a);

#endif