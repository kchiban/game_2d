/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiban <kchiban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:21:20 by kchiban           #+#    #+#             */
/*   Updated: 2022/11/23 17:21:24 by kchiban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long a)
{
	int	i;

	i = 0;
	if (a < 0)
	{
		i += ft_putchar('-');
		a *= -1;
	}
	if (a > 9)
	{
		i += ft_putnbr(a / 10);
		i += ft_putnbr(a % 10);
	}
	else
		i += ft_putchar(a + '0');
	return (i);
}
