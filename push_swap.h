/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:30:57 by mapichec          #+#    #+#             */
/*   Updated: 2024/02/02 16:09:22 by mapichec         ###   ########.fr       */
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

#endif