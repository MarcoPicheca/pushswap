/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:00:50 by mapichec          #+#    #+#             */
/*   Updated: 2024/01/14 15:20:36 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_int(int n)
{
	int	c;

	c = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		c++;
		n = n / 10;
	}
	return (c);
}

int	len_uns(unsigned int n)
{
	unsigned int	c;

	c = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		c++;
		n = n / 10;
	}
	return (c);
}

int	len_ptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	while (ptr > 0)
	{
		ptr = ptr / 16;
		len++;
	}
	return (len);
}

int	len_hex(unsigned int hex)
{
	int	len;

	len = 0;
	if (hex == 0)
		return (1);
	while (hex > 0)
	{
		hex = hex / 16;
		len++;
	}
	return (len);
}
