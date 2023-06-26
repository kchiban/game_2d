/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiban <kchiban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:21:40 by kchiban           #+#    #+#             */
/*   Updated: 2022/11/23 17:22:38 by kchiban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <string.h>

int	ft_putstr(char *s);
int	ft_putchar(char c);
int	ft_putnbr(long c);
int	ft_printf(const char *str, ...);
int	ft_hexnum(unsigned int n);
int	ft_uphexnum(unsigned int n);
int	ft_unsnum(unsigned int n);
int	ft_print_ptr(unsigned long long n);

#endif