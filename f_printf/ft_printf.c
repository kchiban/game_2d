/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiban <kchiban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:20:35 by kchiban           #+#    #+#             */
/*   Updated: 2023/05/31 19:04:34 by kchiban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_next1(char str, int i, va_list arg)
{
	if (str == 's' )
		i += ft_putstr(va_arg(arg, char *));
	else if (str == 'c')
		i += ft_putchar(va_arg(arg, int));
	else if (str == 'd' || str == 'i')
		i += ft_putnbr(va_arg(arg, int));
	else if (str == 'u')
		i += ft_unsnum(va_arg(arg, int));
	else if (str == 'x')
		i += ft_hexnum(va_arg(arg, unsigned int));
	else if (str == 'X')
		i += ft_uphexnum(va_arg(arg, unsigned int));
	else if (str == 'p')
	{
		i += ft_putstr("0x");
		i += ft_print_ptr(va_arg(arg, unsigned long long));
	}
	else if (str == '%')
		i += ft_putchar(str);
	else
		i += ft_putchar(str);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;

	i = 0;
	va_start(arg, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			i = ft_next1(*str, i, arg);
		}
		else
		{
			i += write(1, str, 1);
		}
		str++;
		va_end(arg);
	}
	return (i);
}
