/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:47:24 by mapichec          #+#    #+#             */
/*   Updated: 2024/01/10 18:22:42 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_address(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr >= 16)
	{
		ft_address(ptr / 16);
		ft_address(ptr % 16);
	}
	else if (ptr >= 10 && ptr < 16)
		ft_putchar_len(ptr - 10 + 'a');
	else if (ptr < 10)
	{
		ft_putchar_len(ptr + 48);
	}
	return (len += len_ptr(ptr));
}

int	ft_putptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (!ptr)
	{
		len += write(1, "(nil)", 5);
		return (len);
	}
	else if (ptr)
	{
		len += write(1, "0x", 2);
		len += ft_address(ptr);
	}
	return (len);
}
