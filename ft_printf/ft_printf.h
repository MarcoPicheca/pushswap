/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:56:18 by mapichec          #+#    #+#             */
/*   Updated: 2024/01/13 18:47:44 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <unistd.h>

int	indicatore(char form, va_list arg);
int	ft_putchar_len(int c);
int	ft_putstr_len(char *str);
int	ft_putuns(unsigned int nbr);
int	ft_putnbr_len(int n);
int	ft_putptr(unsigned long long ptr);
int	ft_printf(const char *format, ...);
int	ft_puthexa_m(unsigned int hex);
int	ft_hexprint_m(unsigned int hex);
int	ft_puthexa(unsigned int hex);
int	ft_hexprint(unsigned int hex);
int	ft_address(unsigned long long ptr);
int	len_int(int n);
int	len_hex(unsigned int hex);
int	len_uns(unsigned int n);
int	len_ptr(unsigned long long ptr);

#endif