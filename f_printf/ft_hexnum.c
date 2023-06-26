/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexnum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiban <kchiban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:51:06 by kchiban           #+#    #+#             */
/*   Updated: 2022/11/23 17:17:00 by kchiban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexnum(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 16)
	{
		i += ft_hexnum(n / 16);
		i += ft_hexnum(n % 16);
	}
	if (n < 16 && n > 9)
		i += ft_putchar(n + 87);
	if (n <= 9)
		i += ft_putchar(n + '0');
	return (i);
}
