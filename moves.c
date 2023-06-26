/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiban <kchiban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:33:47 by kchiban           #+#    #+#             */
/*   Updated: 2023/05/31 12:27:46 by kchiban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_player_map(t_draw *data)
{
	if (data->str[data->player_i][data->player_j - 1] == '0'
		|| data->str[(data->player_i)][data->player_j - 1] == 'C'
			|| data->str[data->player_i][data->player_j - 1] == 'E')
	{
		if (data->str[data->player_i][data->player_j - 1] == 'C')
			data->collection--;
		if (data->str[data->player_i][data->player_j - 1] == 'E'
			&& data->collection == 0)
			(mlx_destroy_window(data->mlx, data->mlx_win), exit(1));
		if (data->str[data->player_i][data->player_j - 1] == '0'
			|| data->str[(data->player_i)][data->player_j - 1] == 'C')
		{
			ft_images("textures/floor.xpm", data, data->player_j,
				data->player_i);
			ft_images("textures/player.xpm", data, (data->player_j - 1),
				data->player_i);
			data->move++;
			ft_printf("you moved :%d\n", data->move);
			data->str[data->player_i][(data->player_j - 1)] = 'P';
			data->str[data->player_i][data->player_j] = '0';
			data->player_j = data->player_j - 1;
		}
	}
}

void	change_player_map1(t_draw *data)
{
	if (data->str[(data->player_i)][data->player_j + 1] == '0'
		|| data->str[(data->player_i)][data->player_j + 1] == 'C'
			|| data->str[data->player_i][data->player_j + 1] == 'E')
	{
		if (data->str[data->player_i][data->player_j + 1] == 'C')
			data->collection--;
		if (data->str[data->player_i][data->player_j + 1] == 'E'
			&& data->collection == 0)
			(mlx_destroy_window(data->mlx, data->mlx_win), exit(1));
		if (data->str[(data->player_i)][data->player_j + 1] == '0'
			|| data->str[(data->player_i)][data->player_j + 1] == 'C')
		{
			ft_images("textures/floor.xpm", data, data->player_j,
				data->player_i);
			ft_images("textures/player.xpm", data, (data->player_j + 1),
				data->player_i);
			data->move++;
			ft_printf("you moved :%d\n", data->move);
			data->str[data->player_i][(data->player_j + 1)] = 'P';
			data->str[data->player_i][data->player_j] = '0';
			data->player_j = data->player_j + 1;
		}
	}
}

void	change_player_map2(t_draw *data)
{
	if (data->str[data->player_i + 1][(data->player_j)] == '0'
		|| data->str[data->player_i + 1][data->player_j] == 'C'
			|| data->str[data->player_i + 1][data->player_j] == 'E')
	{
		if (data->str[data->player_i + 1][data->player_j] == 'C')
			data->collection--;
		if (data->str[data->player_i + 1][data->player_j] == 'E'
			&& data->collection == 0)
			(mlx_destroy_window(data->mlx, data->mlx_win), exit(1));
		if (data->str[data->player_i + 1][(data->player_j)] == '0'
			|| data->str[data->player_i + 1][data->player_j] == 'C')
		{
			ft_images("textures/floor.xpm", data, data->player_j,
				data->player_i);
			ft_images("textures/player.xpm", data, data->player_j,
				(data->player_i + 1));
			data->move++;
			ft_printf("you moved :%d\n", data->move);
			data->str[(data->player_i + 1)][data->player_j] = 'P';
			data->str[data->player_i][data->player_j] = '0';
			data->player_i = data->player_i + 1;
		}
	}
}

void	change_player_map3(t_draw *data)
{
	if (data->str[data->player_i - 1][(data->player_j)] == '0'
		|| data->str[data->player_i - 1][data->player_j] == 'C'
			|| data->str[data->player_i - 1][data->player_j] == 'E')
	{
		if (data->str[data->player_i - 1][data->player_j] == 'C')
			data->collection--;
		if (data->str[data->player_i - 1][data->player_j] == 'E'
			&& data->collection == 0)
			(mlx_destroy_window(data->mlx, data->mlx_win), exit(1));
		if (data->str[data->player_i - 1][(data->player_j)] == '0'
			|| data->str[data->player_i - 1][data->player_j] == 'C')
		{
			ft_images("textures/floor.xpm", data, data->player_j,
				data->player_i);
			ft_images("textures/player.xpm", data, data->player_j,
				(data->player_i - 1));
			data->move++;
			ft_printf("you moved :%d\n", data->move);
			data->str[(data->player_i - 1)][data->player_j] = 'P';
			data->str[data->player_i][data->player_j] = '0';
			data->player_i = data->player_i - 1;
		}
	}
}
