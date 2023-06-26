/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiban <kchiban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:04:07 by kchiban           #+#    #+#             */
/*   Updated: 2023/06/08 01:10:00 by kchiban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(t_draw *data)
{
	int	i;
	int	s;

	i = -1;
	while (data->check_path[++i])
	{
		s = -1;
		while (data->check_path[i][++s])
		{	
			data->collection += (data->check_path[i][s] == 'C');
			data->exit += (data->check_path[i][s] == 'E');
			if (data->check_path[i][s] == 'P')
			{
				data->player++;
				data->player_j = s;
				data->player_i = i;
			}
		}
	}
	if (data->collection == 0)
		print_error("add some collectibles !");
	if (data->exit != 1)
		print_error("check the exit !");
	if (data->player != 1)
		print_error("check the player !");
}
