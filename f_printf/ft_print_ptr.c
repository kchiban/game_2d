/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiban <kchiban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:39:31 by kchiban           #+#    #+#             */
/*   Updated: 2022/11/23 17:17:11 by kchiban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(unsigned long long n)
{
	int	i;

	i = 0;
	if (n >= 16)
	{
		i += ft_print_ptr(n / 16);
		i += ft_print_ptr(n % 16);
	}
	if (n < 16 && n > 9)
		i += ft_putchar(n + 87);
	if (n <= 9)
		i += ft_putchar(n + 48);
	return (i);
}
