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

# define	INT_MIN -2147483648
# define	INT_MAX 2147483648
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <signal.h>
# include <stdio.h>

// funzioni base libft 
typedef struct s_list
{
	int			content;
	struct s_list	*next;
}	t_list;
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstnew(int content);
char	*ft_itoa(int n);
int     ft_strlen(const char *str);
int		ft_atoi(const char *str);
void	ft_lstadd_back(t_list **lst, t_list *new);

// Le mosse
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

// le funzioni check
int	check_double(t_list *stack_a);
int	correct_combo(t_list *stack_a);
int	ft_check(char *argv);
void	ft_free_error(&stack_a, &stack_b);

// min e max in array
int	min_int(int *j);
int	max_int(int *j);
int	*ft_arr_int(t_list *stack_a, int *j);

// main function
t_list	**stackato(char *argv, t_list **stack_a);
t_list	*ft_swap_5(t_list *stack_a, t_list *stack_b);
void	swap3(t_list *stack_a);

#endif

