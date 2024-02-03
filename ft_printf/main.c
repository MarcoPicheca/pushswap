/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:59:32 by mapichec          #+#    #+#             */
/*   Updated: 2024/01/14 15:21:47 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	indicatore(char form, va_list arg)
{
	int	len;

	len = 0;
	if (form == 'c')
		len += ft_putchar_len(va_arg(arg, int));
	else if (form == 's')
		len += ft_putstr_len(va_arg(arg, char *));
	else if (form == 'd' || form == 'i')
		len += ft_putnbr_len(va_arg(arg, int));
	else if (form == 'u')
		len += ft_putuns(va_arg(arg, unsigned int));
	else if (form == 'p')
		len += ft_putptr(va_arg(arg, unsigned long long));
	else if (form == 'x')
		len += ft_puthexa(va_arg(arg, unsigned int));
	else if (form == 'X')
		len += ft_puthexa_m(va_arg(arg, unsigned int));
	else if (form == '%')
		len += ft_putchar_len('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	arg;

	va_start(arg, format);
	i = 0;
	len = 0;
	if (!format)
		return (0);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			len += indicatore(format[i], arg);
		}
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(arg);
	return (len);
}
/* int main()
{
	int i = INT_MIN;
	char c = 'g';
	char *f = NULL;
	void *p = "0xfffffff";
	unsigned int x = 0;
	unsigned int bg = 1332;
	int	tr = 0;
	int fk = 0;

	fk = ft_printf("fake cioa\n");
	tr = printf("vera cioa\n");
	fk = ft_printf("fake %c\n%s\n%p\n%d\n%i\n%u\nsono qui %x\n%X\n"
	, c, "", p, i, i, bg, LONG_MIN, x);
	tr = printf("vera %c\n%s\n%p\n%d\n%i\n%u\nsono qui %x\n%X\n", c
	, "", p, i, i, bg, LONG_MIN, x);
	// tr = printf("cspdiuxX%%\n");
	ft_printf("fk = %d || tr = %d\n", fk, tr);
	// fk = ft_printf("fake str %s\n", f);
	// tr = printf("vera str %s\n", f);
	// ft_printf("fk = %d || tr = %d\n", fk, tr);
	// fk = ft_printf("fake pointer %p\n", p);
	// tr = printf("vera pointer %p\n", p);
	// ft_printf("fk = %d || tr = %d\n", fk, tr);
	// fk = ft_printf("fake int %d e %i\n", i, i);
	// tr = printf("vera int %d e %i\n", i, i);
	// ft_printf("fk = %d || tr = %d\n", fk, tr);
	// fk = ft_printf("fake hex %x e %X\n", x, x);
	// tr = printf("vera hex %x e %X\n", x, x);
	// ft_printf("fk = %d || tr = %d\n", fk, tr);
	// fk = ft_printf("fake %c\n", c);
	// tr = printf("vera %c\n", c);
	// ft_printf("fk = %d || tr = %d\n", fk, tr);
	return (0);
} */
