/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:53:34 by mapichec          #+#    #+#             */
/*   Updated: 2024/03/21 11:54:41 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	sign = 1;
	res = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' && (nptr[i + 1] < '0' || nptr[i] > '9'))
		return (res);
	else if (nptr[i] == '+' && (nptr[i + 1] >= '0' && nptr[i] <= '9'))
		i++;
	if (nptr[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (nptr[i] != '\0' && nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - 48);
		i++;
	}
	return (res * sign);
}

int	arg_exist(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 33 && str[i] <= 126)
			return (0);
		i++;
	}
	return (1);
}

int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == '+' || str[i] == '-' || str[i] == 32) && str[i] != '\0')
			i++;
		if (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
		{
			i++;
			if (str[i] == '-' || str[i] == '+')
				return (1);
		}
		else if ((str[i] < '0' || str[i] > '9')
			&& str[i] != 32 && str[i] != '\0' && str[i] != '-'
			&& str[i] != '+')
			return (1);
	}
	if (!arg_exist(str))
		return (0);
	return (1);
}

int	ft_isspace(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 32)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
