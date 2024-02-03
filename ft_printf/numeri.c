/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numeri.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:44:48 by mapichec          #+#    #+#             */
/*   Updated: 2024/01/12 17:01:48 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_len(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		return (len += ft_putstr_len("-2147483648"));
	else
	{
		if (n < 0)
		{
			ft_putchar_len('-');
			len = 1;
			n *= -1;
		}
		if (n > 9)
			ft_putnbr_len(n / 10);
		ft_putchar_len((n % 10) + 48);
	}
	return (len += len_int(n));
}

int	ft_putuns(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr >= 10)
		ft_putuns(nbr / 10);
	ft_putchar_len((nbr % 10) + 48);
	return (len += len_uns(nbr));
}
