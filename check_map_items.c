/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_items.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiban <kchiban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:26:51 by kchiban           #+#    #+#             */
/*   Updated: 2023/06/08 00:54:03 by kchiban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_items(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 'P' && str[i] != 'E' && str[i] != 'C'
			&& str[i] != '1' && str[i] != '0' && str[i] != '\n')
			print_error("please check the characters !");
		i++;
	}
}
