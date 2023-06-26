/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiban <kchiban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:45:08 by kchiban           #+#    #+#             */
/*   Updated: 2023/05/30 17:05:49 by kchiban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	images(t_draw *data)
{
	int	x;
	int	z;

	x = 0;
	while (data->str[x])
	{
		z = 0;
		while (data->str[x][z])
		{
			if (data->str[x][z] == '1')
				ft_images("textures/walls.xpm", data, z, x);
			if (data->str[x][z] == '0')
				ft_images("textures/floor.xpm", data, z, x);
			if (data->str[x][z] == 'P')
				ft_images("textures/player.xpm", data, z, x);
			if (data->str[x][z] == 'C')
				ft_images("textures/collections.xpm", data, z, x);
			if (data->str[x][z] == 'E')
				ft_images("textures/exit.xpm", data, z, x);
			z++;
		}
		x++;
	}
}
