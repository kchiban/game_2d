/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiban <kchiban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:58:50 by kchiban           #+#    #+#             */
/*   Updated: 2023/06/08 01:14:18 by kchiban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	inis_struct(t_draw *data)
{
	data->collection = 0;
	data->player = 0;
	data->exit = 0;
	data->img_height = 50;
	data->img_width = 50;
}

void	set_data(t_draw **data, char **av)
{
	char	*line;
	char	*lines_all;

	(*data) = malloc(sizeof(t_draw) * 1);
	inis_struct(*data);
	(*data)->len = ft_strlen(av[1]);
	if (ft_strncmp(".ber", av[1] + (*data)->len - 4, 4) != 0)
		print_error("check your file name !");
	(*data)->fd = open(av[1], O_RDONLY);
	if ((*data)->fd == -1)
		print_error("No file exists with this name !");
	while (1)
	{
		line = get_next_line((*data)->fd);
		if (line == NULL)
			break ;
		lines_all = ft_strjoin(lines_all, line);
		free(line);
	}
	check_new_line(lines_all);
	check_map_items(lines_all);
	(*data)->str = ft_split(lines_all, '\n');
	(*data)->check_path = ft_split(lines_all, '\n');
	(*data)->check_pat = ft_split(lines_all, '\n');
	free(lines_all);
}

void	check_new_line(char *str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (!str)
		print_error("Incomplete or empty map !");
	while (str[j])
		j++;
	while (str[i])
	{
		if ((str[i] == '\n' && str[i + 1] == '\n')
			|| str[0] == '\n' || str[j - 1] == '\n')
			print_error("remove the newline !");
		i++;
	}
}

int	main(int ac, char **av)
{
	t_draw	*data;

	data = NULL;
	if (ac != 2)
		return (1);
	set_data(&data, av);
	parsing(data);
	check_map(data);
	check_path1(data->player_i, data->player_j, data);
	check_path(data->player_i, data->player_j, data);
	check_path_valid(data);
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, (data->map_char + 1)
			* data->img_width, (data->map_len + 1)
			* data->img_height, "so_long");
	images(data);
	data->move = 0;
	mlx_hook(data->mlx_win, 2, 0, render, data);
	mlx_hook(data->mlx_win, 17, 0, mouse, data);
	mlx_loop(data->mlx);
	return (0);
}
