/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiban <kchiban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:46:26 by kchiban           #+#    #+#             */
/*   Updated: 2023/06/08 00:36:17 by kchiban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parsing(t_draw *data)
{
	int	i;

	i = 0;
	while (data->str[i])
		i++;
	if (!data->str || i < 2)
		print_error("Incomplete or empty map !");
	wall_e(data->str, data);
	wall_a(data->str, data);
	wall_b(data->str, data);
	wall_c(data->str, data);
	wall_d(data->str, data);
}

void	check_path(int i, int j, t_draw *data)
{
	if (i < 0 || j < 0 || i >= data->map_len || j >= data->map_char
		|| data->check_pat[i][j] == '1')
		return ;
	data->check_pat[i][j] = '1';
	check_path(i + 1, j, data);
	check_path(i - 1, j, data);
	check_path(i, j + 1, data);
	check_path(i, j - 1, data);
}

int	mouse(void)
{
	exit(0);
}

int	render(int nbr, t_draw *data)
{
	if (nbr == 123 || nbr == 0)
		change_player_map(data);
	else if (nbr == 124 || nbr == 2)
		change_player_map1(data);
	else if (nbr == 125 || nbr == 1)
		change_player_map2(data);
	else if (nbr == 126 || nbr == 13)
		change_player_map3(data);
	else if (nbr == 53)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit(1);
	}
	return (0);
}

void	ft_images(char *str, t_draw *data, int i, int j)
{
	data->img = mlx_xpm_file_to_image(data->mlx, str, &data->img_width,
			&data->img_height);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img,
		i * 50, j * 50);
}
