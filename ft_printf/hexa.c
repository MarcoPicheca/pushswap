/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:45:01 by mapichec          #+#    #+#             */
/*   Updated: 2024/02/03 10:15:59 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexprint(unsigned int hex)
{
	int	len;

	len = 0;
	if (hex >= 16)
	{
		ft_hexprint(hex / 16);
		ft_hexprint(hex % 16);
	}
	else if (hex >= 10 && hex < 16)
		ft_putchar_len(hex - 10 + 'a');
	else if (hex < 10)
	{
		ft_putchar_len(hex + 48);
	}
	return (len += len_hex(hex));
}

int	ft_puthexa(unsigned int hex)
{
	int	len;

	len = 0;
	if (hex > 0)
		len += ft_hexprint(hex);
	return (len);
}

int	ft_hexprint_m(unsigned int hex)
{
	int	len;

	len = 0;
	if (hex >= 16)
	{
		ft_hexprint_m(hex / 16);
		ft_hexprint_m(hex % 16);
	}
	else if (hex >= 10 && hex < 16)
		ft_putchar_len(hex - 10 + 'A');
	else if (hex < 10)
	{
		ft_putchar_len(hex + 48);
	}
	return (len += len_hex(hex));
}

int	ft_puthexa_m(unsigned int hex)
{
	int	len;

	len = 0;
	if (hex > 0)
		len += ft_hexprint_m(hex);
	return (len);
}
