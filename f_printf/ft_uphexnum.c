/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uphexnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiban <kchiban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:19:37 by kchiban           #+#    #+#             */
/*   Updated: 2022/11/23 17:16:10 by kchiban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_uphexnum(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 16)
	{
		i += ft_uphexnum(n / 16);
		i += ft_uphexnum(n % 16);
	}
	if (n < 16 && n > 9)
		i += ft_putchar(n + 55);
	if (n <= 9)
		i += ft_putchar(n + '0');
	return (i);
}
