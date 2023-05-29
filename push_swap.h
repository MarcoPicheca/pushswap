
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
int     ft_strlen(const char *str);
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
int	    check_double(t_list *stack_a);
t_list	**stackato(char *argv, t_list **stack_a);
int	check_double(t_list *stack_a);

#endif
