/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsnum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiban <kchiban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:19:40 by kchiban           #+#    #+#             */
/*   Updated: 2022/11/23 17:16:43 by kchiban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsnum(unsigned int a)
{
	int	i;

	i = 0;
	if (a > 9)
	{
		i += ft_unsnum(a / 10);
		i += ft_unsnum(a % 10);
	}
	else
		i += ft_putchar(a + '0');
	return (i);
}
